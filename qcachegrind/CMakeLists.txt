set(qcachegrind_SRCS qcgmain.cpp qcgtoplevel.cpp qcgconfig.cpp
		     configdialog.cpp configpage.cpp qtcolorbutton.cpp
		     generalsettings.cpp sourcesettings.cpp colorsettings.cpp)

qt5_wrap_ui(qcachegrind_H generalsettings.ui sourcesettings.ui colorsettings.ui)
qt5_add_resources(qcachegrind_RSRC qcachegrind.qrc)

add_executable(qcachegrind ${qcachegrind_SRCS} ${qcachegrind_H} ${qcachegrind_RSRC})

target_link_libraries(qcachegrind
        core views
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::DBus)

if(APPLE)
        
  set_target_properties(qcachegrind PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in
    MACOSX_BUNDLE_ICON_FILE kcachegrind.icns
    )
  
  # bundle stuff
  set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
  set(DATA_INSTALL_DIR   "qcachegrind.app/Contents/Resources")

  if(QT_MAC_USE_COCOA AND EXISTS "${QT_LIBRARY_DIR}/Resources/qt_menu.nib")
    install(DIRECTORY "${QT_LIBRARY_DIR}/Resources/qt_menu.nib"
            DESTINATION "${DATA_INSTALL_DIR}")
  endif()

  install(FILES kcachegrind.icns
    DESTINATION "${DATA_INSTALL_DIR}")
  
endif(APPLE)
      

# do not install example code...
# install(TARGETS qcachegrind ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} )
