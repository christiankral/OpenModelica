/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Linkoping University,
 * Department of Computer and Information Science,
 * SE-58183 Linkoping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 
 * AND THIS OSMC PUBLIC LICENSE (OSMC-PL). 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S  
 * ACCEPTANCE OF THE OSMC PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linkoping University, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or  
 * http://www.openmodelica.org, and in the OpenModelica distribution. 
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main Authors 2010: Syed Adeel Asghar, Sonia Tariq
 *
 */

#ifndef TEXTANNOTATION_H
#define TEXTANNOTATION_H

#include "ShapeAnnotation.h"
#include "Component.h"
#include "mainwindow.h"

class OMCProxy;
class IconParameters;

class TextAnnotation : public ShapeAnnotation
{
    Q_OBJECT
private:
    QString mTextString;
    qreal mFontSize;
    QString mFontName;
    int mFontWeight;
    bool mFontItalic;    
    bool mFontUnderLine;
    //double mDefaultFontSize;
    Qt::Alignment mHorizontalAlignment;
public:
    TextAnnotation(QString shape, Component *pParent = 0);
    TextAnnotation(GraphicsView *graphicsView, QGraphicsItem *pParent = 0);
    TextAnnotation(QString shape, GraphicsView *graphicsView, QGraphicsItem *pParent = 0);    

    QRectF boundingRect() const;
    QString getTextString();
    QPainterPath shape() const;
    QString getShapeAnnotation();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void checkNameString();
    void checkParameterString();
    bool updateParameterString(IconParameters *pParamter);
    void setTextString(QString text);
    void setFontName(QString fontName);
    void setFontSize(double fontSize);
    void setItalic(bool italic);
    void setWeight(int bold);
    void setUnderLine(bool underLine);
    void setAlignment(Qt::Alignment alignment);
    void drawRectangleCornerItems();
    void updateEndPoint(QPointF point);
    void addPoint(QPointF point);
    void updateAnnotation();
    void parseShapeAnnotation(QString shape, OMCProxy *omc);

    Component *mpComponent;
public slots:
    void updatePoint(int index, QPointF point);
};

class TextWidget : public QDialog
{
    Q_OBJECT
public:
    TextWidget(TextAnnotation *pTextShape, MainWindow *parent = 0);
    MainWindow *mpParentMainWindow;
    void setUpForm();
    void show();    

private:
   QLabel *mpTextLabel;
   QLineEdit *mpTextBox;
   QLabel *mpFontLabel;   
   QLabel *mpFontSizeLabel;
   QPushButton *mpEditButton;
   QPushButton *mpCancelButton;
   QDialogButtonBox *mpButtonBox;
   QGroupBox *mpTextGroup;
   QGroupBox *mpFontGroup;
   QGroupBox *mpFontSizeGroup;

   QCheckBox *mpCursive;
   QCheckBox *mpBold;
   QCheckBox *mpUnderline;
   QGroupBox *mpStyleGroup;

   QFontComboBox *mpFontFamilyComboBox;
   QComboBox *mpFontSizeComboBox;

   QComboBox *mpAlignmentComboBox;
   QGroupBox *mpAlignmentGroup;
   QLabel *mpAlignmentLabel;

   TextAnnotation *mpTextAnnotation;
public slots:
    void edit();
};

#endif // TEXTANNOTATION_H
