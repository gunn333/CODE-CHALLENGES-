//! Reveal Cards In Increasing Order (Leetcode 950)

// Question Link:
// https://leetcode.com/problems/reveal-cards-in-increasing-order/

#include <bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck) {
  int n = deck.size();

  sort(deck.begin(), deck.end());

  // Reordered deck jismein 0 paenge taki baad mein check kr sake ki deck reveal
  // ho gya ya nai
  vector<int> reorderedDeck(n, 0);
  // Revealed cards = 1 because 0th card is already revealed
  int revealedCards = 1;
  // count is used to keep track of the number of iterations
  int count = 0;

  // Jab tak saare cards reveal nahi ho jaate
  while (revealedCards <= n) {
    // deck iterate
    for (int i = 0; i < n; i++) {
      // agar card reveal nahi hua hai toh usko reveal karo
      if (reorderedDeck[i] == 0) {
        // count even hai toh card reveal karo because even cards are revealed
        // first in the deck reveal process
        if (count % 2 == 0) {
          // current card ko deck mein add karo
          // revealed cards - 1 because 0 based indexing
          reorderedDeck[i] = deck[revealedCards - 1];
          // increase the number of revealed cards because we have revealed a
          // card now
          revealedCards++;
        }
        // count increase karo because we have iterated over a card
        // The count variable ensures that cards are revealed in an orderly
        // manner according to the problem's rule of revealing every second
        // unrevealed card. It helps maintain the alternating reveal pattern and
        // ensures that the correct number of cards are revealed until all cards
        // are revealed.
        count++;
      }
    }
  }
  return reorderedDeck;
}

int main() {
  vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
  vector<int> result = deckRevealedIncreasing(deck);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}