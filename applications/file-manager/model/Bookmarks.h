#pragma once

#include <libsystem/io/File.h>
#include <libsystem/json/Json.h>
#include <libutils/Observable.h>
#include <libutils/Vector.h>

#include "file-manager/model/Bookmark.h"

namespace file_manager
{

class Bookmarks :
    public Observable<Bookmarks>,
    public RefCounted<Bookmarks>
{
private:
    Vector<Bookmark> _bookmarks{};

public:
    Bookmarks()
    {
    }

    const Vector<Bookmark> &all() const;

    void add(Bookmark &&bookmark);

    void remove(const Path &path);

    bool has(const Path &path) const;

    static RefPtr<Bookmarks> load();

    void save();
};

} // namespace file_manager
