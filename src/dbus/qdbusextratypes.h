/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtDBus module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDBUSEXTRATYPES_H
#define QDBUSEXTRATYPES_H

// define some useful types for D-BUS

#include <QtCore/qvariant.h>
#include <QtCore/qstring.h>
#include <QtDBus/qdbusmacros.h>
#include <QtCore/qhash.h>

#ifndef QT_NO_DBUS

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE


class Q_DBUS_EXPORT QDBusObjectPath
{
    QString m_path;
public:
    inline QDBusObjectPath() { }

    inline explicit QDBusObjectPath(const char *path);
    inline explicit QDBusObjectPath(const QLatin1String &path);
    inline explicit QDBusObjectPath(const QString &path);

    inline void setPath(const QString &path);

    inline QString path() const
    { return m_path; }

private:
    void doCheck();
};

inline QDBusObjectPath::QDBusObjectPath(const char *objectPath)
    : m_path(QString::fromLatin1(objectPath))
{ doCheck(); }

inline QDBusObjectPath::QDBusObjectPath(const QLatin1String &objectPath)
    : m_path(objectPath)
{ doCheck(); }

inline QDBusObjectPath::QDBusObjectPath(const QString &objectPath)
    : m_path(objectPath)
{ doCheck(); }

inline void QDBusObjectPath::setPath(const QString &objectPath)
{ m_path = objectPath; doCheck(); }

inline bool operator==(const QDBusObjectPath &lhs, const QDBusObjectPath &rhs)
{ return lhs.path() == rhs.path(); }

inline bool operator!=(const QDBusObjectPath &lhs, const QDBusObjectPath &rhs)
{ return lhs.path() != rhs.path(); }

inline bool operator<(const QDBusObjectPath &lhs, const QDBusObjectPath &rhs)
{ return lhs.path() < rhs.path(); }

inline uint qHash(const QDBusObjectPath &objectPath)
{ return qHash(objectPath.path()); }


class Q_DBUS_EXPORT QDBusSignature
{
    QString m_signature;
public:
    inline QDBusSignature() { }

    inline explicit QDBusSignature(const char *signature);
    inline explicit QDBusSignature(const QLatin1String &signature);
    inline explicit QDBusSignature(const QString &signature);

    inline void setSignature(const QString &signature);

    inline QString signature() const
    { return m_signature; }

private:
    void doCheck();
};

inline QDBusSignature::QDBusSignature(const char *dBusSignature)
    : m_signature(QString::fromAscii(dBusSignature))
{ doCheck(); }

inline QDBusSignature::QDBusSignature(const QLatin1String &dBusSignature)
    : m_signature(dBusSignature)
{ doCheck(); }

inline QDBusSignature::QDBusSignature(const QString &dBusSignature)
    : m_signature(dBusSignature)
{ doCheck(); }

inline void QDBusSignature::setSignature(const QString &dBusSignature)
{ m_signature = dBusSignature; doCheck(); }

inline bool operator==(const QDBusSignature &lhs, const QDBusSignature &rhs)
{ return lhs.signature() == rhs.signature(); }

inline bool operator!=(const QDBusSignature &lhs, const QDBusSignature &rhs)
{ return lhs.signature() != rhs.signature(); }

inline bool operator<(const QDBusSignature &lhs, const QDBusSignature &rhs)
{ return lhs.signature() < rhs.signature(); }

inline uint qHash(const QDBusSignature &signature)
{ return qHash(signature.signature()); }

class QDBusVariant
{
    QVariant m_variant;
public:
    inline QDBusVariant() { }
    inline explicit QDBusVariant(const QVariant &variant);

    inline void setVariant(const QVariant &variant);

    inline QVariant variant() const
    { return m_variant; }
};

inline  QDBusVariant::QDBusVariant(const QVariant &dBusVariant)
    : m_variant(dBusVariant) { }

inline void QDBusVariant::setVariant(const QVariant &dBusVariant)
{ m_variant = dBusVariant; }

inline bool operator==(const QDBusVariant &v1, const QDBusVariant &v2)
{ return v1.variant() == v2.variant(); }

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QDBusVariant)
Q_DECLARE_METATYPE(QDBusObjectPath)
Q_DECLARE_METATYPE(QList<QDBusObjectPath>)
Q_DECLARE_METATYPE(QDBusSignature)
Q_DECLARE_METATYPE(QList<QDBusSignature>)

QT_END_HEADER

#endif // QT_NO_DBUS
#endif
