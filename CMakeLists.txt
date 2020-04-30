cmake_minimum_required(VERSION 3.10)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11 CACHE STRING "Build for 10.11")

project(tuning-workbench-synth VERSION 0.9.0 LANGUAGES CXX)

add_subdirectory(lib/JUCE)

execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

juce_add_plugin(tuning-workbench-synth
    PRODUCT_NAME "tuning-workbench-synth"
    COMPANY_NAME "Surge Synth Team"  
    BUNDLE_ID "org.surge-synth-team.tuning-workbench-synth"
    PLUGIN_MANUFACTURER_CODE VmbA
    PLUGIN_CODE TnWB

    ICON_SMALL "Resources/TWSLogo_64.png"
    ICON_BIG   "Resources/TWSLogo_512.png"
    
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    
    FORMATS AU VST3 Standalone
)

juce_generate_juce_header( tuning-workbench-synth )

file(GLOB TWS_RESOURCES_GLOB
  Resources/*.ttf 
  Resources/*.png 
  Resources/*.svg
  Resources/factory_patches/*.twsxml
  )

juce_add_binary_data( tuning-workbench-synth-binary
  SOURCES ${TWS_RESOURCES_GLOB}
)

set_target_properties(tuning-workbench-synth-binary PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE)
    
target_include_directories(tuning-workbench-synth 
  PRIVATE
  Source
  lib/tuning-library/include
)

configure_file(
  ${CMAKE_SOURCE_DIR}/Source/version.cpp.in
  ${CMAKE_BINARY_DIR}/generated/version.cpp
)

target_sources(tuning-workbench-synth PRIVATE
  Source/PluginEditor.cpp
  Source/PluginProcessor.cpp
  Source/TWSAbout.cpp
  Source/TWSKBMGenerator.cpp
  Source/TWSMainPanel.cpp
  Source/TWSTextAndControls.cpp
  Source/TWSTuningGrid.cpp
  Source/TWSVoice.cpp
  ${CMAKE_BINARY_DIR}/generated/version.cpp
)

target_compile_definitions(tuning-workbench-synth PUBLIC
    JUCE_ALLOW_STATIC_NULL_VARIABLES=0
    JUCE_STRICT_REFCOUNTEDPOINTER=1

    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_USE_CURL=0
    JUCE_WEB_BROWSER=0

    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_REPORT_APP_USAGE=0

    JUCE_ALSA=1
    JUCE_JACK=1
)

juce_add_module(
  lib/surgesynthteam_tuningui
)
target_link_libraries(tuning-workbench-synth PRIVATE
    tuning-workbench-synth-binary
    surgesynthteam_tuningui
    juce::juce_analytics
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_blocks_basics
    juce::juce_box2d
    juce::juce_dsp
)

# Build installers
get_target_property( OUTPUT_DIR tuning-workbench-synth RUNTIME_OUTPUT_DIRECTORY )
add_custom_target( installer-pkg )
add_dependencies( installer-pkg tuning-workbench-synth )
set( INSTALLER_DIR ${CMAKE_BINARY_DIR}/asset )
set( INSTALLER_BASENAME "tuning-workbench-synth" )

if( APPLE )
  add_custom_command(
    TARGET installer-pkg
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${INSTALLER_DIR}
    COMMAND hdiutil create ${INSTALLER_DIR}/${INSTALLER_BASENAME}-macos-${GIT_COMMIT_HASH}.dmg -ov -volname "${INSTALLER_BASENAME}-${GIT_COMMIT_HASH}" -fs HFS+ -srcfolder ${OUTPUT_DIR}
    )
elseif( UNIX )
  add_custom_command(
    TARGET installer-pkg
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${INSTALLER_DIR}
    COMMAND ls -l ${OUTPUT_DIR}
    COMMAND cd ${OUTPUT_DIR} && tar cf "${INSTALLER_DIR}/${INSTALLER_BASENAME}-linux-${GIT_COMMIT_HASH}.tgz" "${INSTALLER_BASENAME}" "${INSTALLER_BASENAME}.vst3" 
    )
else()
  file( TO_NATIVE_PATH "${INSTALLER_DIR}/${INSTALLER_BASENAME}-win-${GIT_COMMIT_HASH}.zip" OUTPUT_ZIP )
  message( "Creating ${OUTPUT_ZIP}" )
  add_custom_command(
    TARGET installer-pkg
    POST_BUILD
    WORKING_DIRECTORY ${OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${INSTALLER_DIR}
    COMMAND ls
    COMMAND powershell Compress-Archive 
             -DestinationPath "${OUTPUT_ZIP}"
             -Path "${INSTALLER_BASENAME}.exe", "${INSTALLER_BASENAME}.vst3" 
    )
endif()
