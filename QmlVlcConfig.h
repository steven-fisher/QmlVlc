/*******************************************************************************
* Copyright © 2014-2015, Sergey Radionov <rsatom_gmail.com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#pragma once

#include <QObject>

#include <libvlcpp/vlcpp/vlc.hpp>

//this class is not thread safe
class QmlVlcConfig : public QObject
{
    Q_OBJECT

public:

    static QmlVlcConfig& instance();

    void setNetworkCacheTime( int time );
    void enableAdjustFilter( bool enable );
    void enableMarqueeFilter( bool enable );
    void enableLogoFilter( bool enable );
    void enableFecLog( bool enable );
    void enableNoVideoTitleShow( bool enable );
    void enableHardwareAcceleration( bool enable );

    void setTrustedEnvironment( bool trusted );
    bool trustedEnvironment() const;

    bool isOptionTrusted( const QString& ) const;

    int getlogging() const {
        return _fecLog;
    }

    void setlogging(bool val)
    {
        _fecLog = val;
        emit loggingChanged(val);
    }


    void enableLogging( bool enable ) { setlogging(enable); }

    bool createLibvlcInstance( );

    bool releaseLibvlcInstance( );


    VLC::Instance* getLibvlcInstance();

signals:
    void loggingChanged(int newValue);


private:
    QmlVlcConfig( QObject* parent = nullptr );
    ~QmlVlcConfig();

    QmlVlcConfig( QmlVlcConfig& ) = delete;
    QmlVlcConfig& operator= ( QmlVlcConfig& ) = delete;

private:
    int _networkCacheTime;
    bool _adjustFilter;
    bool _marqueeFilter;
    bool _logoFilter;
    bool _fecLog;
    bool _noVideoTitleShow;
    bool _hardwareAcceleration;
    bool _trustedEnvironment;
    unsigned _libvlcCounter;

    VLC::Instance * _libvlc;
};



class QmlVlcConfigProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY (bool logging READ getlogging WRITE setlogging NOTIFY loggingChanged)

public:

    Q_INVOKABLE void enableLogging( bool enable ) { setlogging(enable); }

    Q_INVOKABLE bool createLibvlcInstance( )  { return QmlVlcConfig::instance( ).createLibvlcInstance( ); }
    Q_INVOKABLE bool releaseLibvlcInstance( ) { return QmlVlcConfig::instance( ).releaseLibvlcInstance( ); }

    QmlVlcConfigProxy( QObject* parent = nullptr );
    ~QmlVlcConfigProxy() {}

    int getlogging() const {    return QmlVlcConfig::instance( ).getlogging( ); }
    void setlogging(bool val) { return QmlVlcConfig::instance( ).setlogging( val ); }

signals:
    void loggingChanged(int newValue);
};

