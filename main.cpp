#include <iostream>
#include <vector>

using namespace std;

vector<int> deck = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
vector<int> active_cards = {};

int choice;
int card_in_play;
int dealt_card;
int score;
int active_deck_size;

bool lost = false;
bool playing = true;

int dealCard(vector<int>& vec, int n) {
    swap(vec[n], vec.back());
    int card = vec.back();
    vec.pop_back();

    return card;
}

int main() {
    while (playing) {
        cout << "Welcome to High-Low! Type 1. to play, type 2. to exit." << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                while (!lost) {
                    if (active_cards.empty()) {
                        active_cards = deck;
                        active_deck_size = 52;
                        cout << "The deck has been shuffled!" << endl;

                        card_in_play = dealCard(active_cards, rand() % active_deck_size);
                        active_deck_size--;
                    }


                    cout << "The card in play is of value: " << card_in_play << endl;
                    invalid_input:
                    cout << "What is your bet? (1. for higher, 2. for lower)" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            dealt_card = dealCard(active_cards, rand() % active_deck_size);
                            active_deck_size--;
                            cout << "You were dealt a card of value: " << dealt_card << endl;

                            if (dealt_card == card_in_play) {
                                cout << "Draw! No points" << endl;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card > card_in_play) {
                                cout << "Score! +1 points" << endl;
                                score++;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card < card_in_play) {
                                cout << "You lose! Final score: " << score << endl;
                                lost = true;
                                break;
                            }

                        case 2:
                            dealt_card = dealCard(active_cards, rand() % active_deck_size);
                            active_deck_size--;
                            cout << "You were dealt a card of value: " << dealt_card << endl;

                            if (dealt_card == card_in_play) {
                                cout << "Draw! No points" << endl;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card < card_in_play) {
                                cout << "Score! +1 points" << endl;
                                score++;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card > card_in_play) {
                                cout << "You lose! Final score: " << score << endl;
                                lost = true;
                                break;
                            }
                        default:
                            goto invalid_input;
                    }
                }
            break;

            case 2:
                playing = false;
                break;

            default:
                break;
        }
    }

    return 0;
}
