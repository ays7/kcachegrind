/* This file is part of KCachegrind.
   Copyright (C) 2003 Josef Weidendorfer <Josef.Weidendorfer@gmx.de>

   KCachegrind is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation, version 2.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

/*
 * PartSelection for KCachegrind
 * For part file selection, to be put into a QDockWindow
 */

#ifndef PARTSELECTION_H
#define PARTSELECTION_H

#include <QWidget>
#include <QPoint>

#include "tracedata.h"

class QLabel;
class TraceFunction;
class TraceData;
class TreeMapItem;
class PartAreaWidget;


class PartSelection: public QWidget
{
  Q_OBJECT

public:
  PartSelection(QWidget* parent = 0);
  virtual ~PartSelection();

  TraceData* data() { return _data; }
  void setData(TraceData*);

  PartAreaWidget* graph() { return _partAreaWidget; }

  void restoreOptions(const QString& prefix, const QString& postfix);
  void saveOptions(const QString& prefix, const QString& postfix);

signals:
  void activePartsChanged(const TracePartList& list);
  void partsHideSelected();
  void partsUnhideAll();
  void groupChanged(TraceCostItem*);
  void functionChanged(TraceItem*);
  void showMessage(const QString&, int);
  void goBack();

public slots:
  void selectionChanged();
  void doubleClicked(TreeMapItem*);
  void contextMenuRequested(TreeMapItem*, const QPoint &);
  void currentChangedSlot(TreeMapItem*, bool);

  void setPart(TracePart*);
  void setEventType(TraceEventType*);
  void setEventType2(TraceEventType*);
  void setGroupType(TraceItem::CostType);
  void setGroup(TraceCostItem*);
  void setFunction(TraceFunction*);
  void activePartsChangedSlot(const TracePartList& list);
  void hiddenPartsChangedSlot(const TracePartList& list);
  void refresh();
  void showInfo(bool);

private:
  void fillInfo();

  TraceData* _data;
  TraceEventType *_eventType, *_eventType2;
  TraceItem::CostType _groupType;
  TraceCostItem* _group;
  TraceFunction* _function;
  bool _showInfo;
  bool _diagramMode;
  bool _drawFrames;
  bool _inSelectionUpdate;

  PartAreaWidget* _partAreaWidget;
  QLabel* _rangeLabel;
};

#endif