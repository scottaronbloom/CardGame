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

#ifndef _GAME_H
#define _GAME_H

#include <memory>

#include <vector>
#include <QString>

class CCard;
class CPlayer;
enum class EHand;

class CGame 
{
public:
    CGame();
    virtual ~CGame();
public:
    std::weak_ptr< CPlayer > currDealer() const{ return fDealer; }

    QString dumpGame() const;
    void shuffleAndDeal();
    void nextDealer();
    void prevDealer();
    void autoSetDealer();
    std::shared_ptr< CPlayer > addPlayer( const QString & name );
    void createPlayers();

    void resetGames();
    size_t numGames() const{ return fGames.size(); }
    QString dumpStats() const;
private:
    void createDeck();

    void shuffleDeck();
    void dealCards();
    QString dumpDeck( bool shuffled ) const;
    QString dumpPlayers() const;

    std::vector< std::shared_ptr< CPlayer > > fPlayers;
    std::weak_ptr< CPlayer > fDealer;
    std::vector< std::shared_ptr< CCard > > fCards; // original and sorted
    std::vector< std::shared_ptr< CCard > > fShuffledCards;

    std::vector< std::pair< EHand, std::weak_ptr< CPlayer > > > fGames;
    std::vector< uint64_t > fWinsByHand;
    std::vector< uint64_t > fWinsByPlayer;

};

#endif // _ALCULATOR_H