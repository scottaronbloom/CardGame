// The MIT License( MIT )
//
// Copyright( c ) 2020 Scott Aron Bloom
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QDialog>
#include <memory>
#include <unordered_map>
#include <functional>
#include <list>
#include <chrono>
#include <optional>
class CGame;
class QComboBox;
class QLabel;
class QLineEdit;
namespace Ui {class CMainWindow;};

class CMainWindow : public QDialog
{
    Q_OBJECT
public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
public Q_SLOTS:
    void slotDeal();
    void slotReanalyzeHand();
    void slotAutoDeal();
    void slotRunAutoDeal();
    void slotNextDealer();
    void slotPrevDealer();
    void slotNumPlayersChanged();
    void slotNumWildCardsChanged();
    void slotWildCardsChanged( bool showGame );
    void slotStraightsAndFlushesCountChanged();
    void slotLowHandWinsChanged();
private:
    void showStats();
    void showGame();
    void loadSettings();

    void setNumCards( int numCards );
    int numCards() const;

    void saveSettings();

    std::unique_ptr< Ui::CMainWindow > fImpl;
    std::shared_ptr< CGame > fGame;
    bool fAutoDealing{ false };

    using TWildCardWidgetVector = std::vector< std::tuple< QLabel*, QComboBox*, QComboBox* > >;
    using TPlayerWidgetVector = std::vector< std::pair< QLabel*, QLineEdit* > >;
    TPlayerWidgetVector fNameWidgets;
    TWildCardWidgetVector fWCWidgets;
    std::optional< std::chrono::system_clock::time_point > fStartTime;
};

#endif // _ALCULATOR_H
