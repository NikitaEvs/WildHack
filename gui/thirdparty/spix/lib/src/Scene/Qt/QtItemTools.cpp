/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "QtItemTools.h"

#include <QQuickItem>

namespace spix {
namespace qt {

const QString repeater_class_name = QString("QQuickRepeater");
const char* item_at_method_name = "itemAt";

QQuickItem* RepeaterChildAtIndex(QQuickItem* repeater, int index)
{
    QQuickItem* retVal = nullptr;
    bool success = QMetaObject::invokeMethod(
        repeater, item_at_method_name, Qt::DirectConnection, Q_RETURN_ARG(QQuickItem*, retVal), Q_ARG(int, index));
    if (success)
        return retVal;

    return nullptr;
}

QQuickItem* RepeaterChildWithName(QQuickItem* repeater, const QString& name)
{
    int itemIndex = 0;
    QQuickItem* item = nullptr;
    do {
        item = RepeaterChildAtIndex(repeater, itemIndex);
        if (item && item->objectName() == name) {
            break;
        }

        ++itemIndex;
    } while (item);

    return item;
}

QObject* FindChildItem(QObject* object, const QString& name)
{
    if (auto qquickitem = qobject_cast<const QQuickItem*>(object)) {
        for (auto child : qquickitem->childItems()) {
            if (child->objectName() == name) {
                return child;
            }
            if (auto item = FindChildItem(child, name)) {
                return item;
            }
        }
    } else {
        for (auto child : object->children()) {
            if (child->objectName() == name) {
                return child;
            }
            if (auto item = FindChildItem(child, name)) {
                return item;
            }
        }
    }

    return nullptr;
}

} // namespace qt
} // namespace spix
