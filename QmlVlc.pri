HEADERS += \
    $$PWD/QmlVlc.h \
    $$PWD/QmlVlcConfig.h \
    $$PWD/QmlVlcPlayerProxy.h \
    $$PWD/QmlVlcPlayer.h \
    $$PWD/QmlVlcVideoSource.h \
    $$PWD/QmlVlcVideoOutput.h \
    $$PWD/QmlVlcVideoFrame.h \
    $$PWD/libvlcpp/vlcpp/common.hpp \
    $$PWD/libvlcpp/vlcpp/Dialog.hpp \
    $$PWD/libvlcpp/vlcpp/Equalizer.hpp \
    $$PWD/libvlcpp/vlcpp/EventManager.hpp \
    $$PWD/libvlcpp/vlcpp/Instance.hpp \
    $$PWD/libvlcpp/vlcpp/Internal.hpp \
    $$PWD/libvlcpp/vlcpp/Media.hpp \
    $$PWD/libvlcpp/vlcpp/MediaDiscoverer.hpp \
    $$PWD/libvlcpp/vlcpp/MediaLibrary.hpp \
    $$PWD/libvlcpp/vlcpp/MediaList.hpp \
    $$PWD/libvlcpp/vlcpp/MediaListPlayer.hpp \
    $$PWD/libvlcpp/vlcpp/MediaPlayer.hpp \
    $$PWD/libvlcpp/vlcpp/structures.hpp \
    $$PWD/vlc-plugins-android.h \
    $$PWD/vlc-plugins-linux.h \
    $$PWD/vlc-plugins-iPhone.h \
    $$PWD/vlc-plugins-raspi.h \
    $$PWD/QmlVlcAudio.h \
    $$PWD/QmlVlcFec.h

HEADERS += \
    $$PWD/libvlcpp/vlcpp/vlc.hpp


SOURCES += \
    $$PWD/QmlVlc.cpp \
    $$PWD/QmlVlcConfig.cpp \
    $$PWD/QmlVlcPlayerProxy.cpp \
    $$PWD/QmlVlcPlayer.cpp \
    $$PWD/QmlVlcVideoSource.cpp \
    $$PWD/QmlVlcVideoOutput.cpp \
    $$PWD/QmlVlcVideoFrame.cpp \
    $$PWD/QmlVlcAudio.cpp

INCLUDEPATH += $$PWD
