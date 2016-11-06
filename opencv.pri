# OPENCV

INCLUDEPATH += $$(OPENCV_DIR)/build/include/
DEPENDPATH += $$(OPENCV_DIR)/build/x64/vc12/lib/

win32:CONFIG(debug, debug|release): LIBS += -L$$(OPENCV_DIR)/build/x64/vc12/lib/ -lopencv_world310d
else:win32:CONFIG(release, debug|release): LIBS += -L$$(OPENCV_DIR)/build/x64/vc12/lib/ -lopencv_world310
