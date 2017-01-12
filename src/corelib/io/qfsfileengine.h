/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QFSFILEENGINE_H
#define QFSFILEENGINE_H

#ifdef QT_JAMBI_BUILD

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "QtCore/qabstractfileengine.h"

#ifndef QT_NO_FSFILEENGINE

QT_BEGIN_NAMESPACE

#if defined(Q_OS_WINCE_STD) && _WIN32_WCE < 0x600
#define Q_USE_DEPRECATED_MAP_API 1
#endif

class QFSFileEnginePrivate;

class Q_CORE_EXPORT QFSFileEngine : public QAbstractFileEngine
{
    Q_DECLARE_PRIVATE(QFSFileEngine)
public:
    QFSFileEngine();
    explicit QFSFileEngine(const QString &file);
    ~QFSFileEngine();

    bool open(QIODevice::OpenMode openMode) Q_DECL_OVERRIDE;
    bool open(QIODevice::OpenMode flags, FILE *fh);
    bool close() Q_DECL_OVERRIDE;
    bool flush() Q_DECL_OVERRIDE;
    bool syncToDisk() Q_DECL_OVERRIDE;
    qint64 size() const Q_DECL_OVERRIDE;
    qint64 pos() const Q_DECL_OVERRIDE;
    bool seek(qint64) Q_DECL_OVERRIDE;
    bool isSequential() const Q_DECL_OVERRIDE;
    bool remove() Q_DECL_OVERRIDE;
    bool copy(const QString &newName) Q_DECL_OVERRIDE;
    bool rename(const QString &newName) Q_DECL_OVERRIDE;
    bool renameOverwrite(const QString &newName) Q_DECL_OVERRIDE;
    bool link(const QString &newName) Q_DECL_OVERRIDE;
    bool mkdir(const QString &dirName, bool createParentDirectories) const Q_DECL_OVERRIDE;
    bool rmdir(const QString &dirName, bool recurseParentDirectories) const Q_DECL_OVERRIDE;
    bool setSize(qint64 size) Q_DECL_OVERRIDE;
    bool caseSensitive() const Q_DECL_OVERRIDE;
    bool isRelativePath() const Q_DECL_OVERRIDE;
    QStringList entryList(QDir::Filters filters, const QStringList &filterNames) const Q_DECL_OVERRIDE;
    FileFlags fileFlags(FileFlags type) const Q_DECL_OVERRIDE;
    bool setPermissions(uint perms) Q_DECL_OVERRIDE;
    QString fileName(FileName file) const Q_DECL_OVERRIDE;
    uint ownerId(FileOwner) const Q_DECL_OVERRIDE;
    QString owner(FileOwner) const Q_DECL_OVERRIDE;
    QDateTime fileTime(FileTime time) const Q_DECL_OVERRIDE;
    void setFileName(const QString &file) Q_DECL_OVERRIDE;
    int handle() const Q_DECL_OVERRIDE;

#ifndef QT_NO_FILESYSTEMITERATOR
    Iterator *beginEntryList(QDir::Filters filters, const QStringList &filterNames) Q_DECL_OVERRIDE;
    Iterator *endEntryList() Q_DECL_OVERRIDE;
#endif

    qint64 read(char *data, qint64 maxlen) Q_DECL_OVERRIDE;
    qint64 readLine(char *data, qint64 maxlen) Q_DECL_OVERRIDE;
    qint64 write(const char *data, qint64 len) Q_DECL_OVERRIDE;

    bool extension(Extension extension, const ExtensionOption *option = 0, ExtensionReturn *output = 0) Q_DECL_OVERRIDE;
    bool supportsExtension(Extension extension) const Q_DECL_OVERRIDE;

    //FS only!!
    bool open(QIODevice::OpenMode flags, int fd);
    bool open(QIODevice::OpenMode flags, int fd, QFile::FileHandleFlags handleFlags);
    bool open(QIODevice::OpenMode flags, FILE *fh, QFile::FileHandleFlags handleFlags);
    static bool setCurrentPath(const QString &path);
    static QString currentPath(const QString &path = QString());
    static QString homePath();
    static QString rootPath();
    static QString tempPath();
    static QFileInfoList drives();

protected:
    QFSFileEngine(QFSFileEnginePrivate &dd);
};

QT_END_NAMESPACE

#endif // QT_NO_FSFILEENGINE

#endif // QT_JAMBI_BUILD

#endif // QFSFILEENGINE_H
