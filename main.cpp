#include <iostream>
#include <vector>

using namespace std;

struct Card {
    string name;
    int value;
};

vector<Card> deck = {{"2 kier", 2},{"2 pik", 2}, {"2 karo", 2}, {"2 trefl", 2},
{"3 kier", 3},{"3 pik", 3}, {"3 karo", 3}, {"3 trefl", 3},
{"4 kier", 4},{"2 pik", 4}, {"4 karo", 4}, {"4 trefl", 4},
{"5 kier", 5},{"5 pik", 5}, {"5 karo", 5}, {"5 trefl", 5},
{"6 kier", 6},{"6 pik", 6}, {"6 karo", 6}, {"6 trefl", 6},
{"7 kier", 7},{"7 pik", 7}, {"7 karo", 7}, {"7 trefl", 7},
{"8 kier", 8},{"8 pik", 8}, {"7 karo", 8}, {"8 trefl", 8},
{"9 kier", 9},{"9 pik", 9}, {"9 karo", 9}, {"9 trefl", 9},
{"10 kier", 10},{"10 pik", 10}, {"10 karo", 10}, {"10 trefl", 10},
{"Walet kier", 11},{"Walet pik", 11}, {"Walet karo", 11}, {"Walet trefl", 11},
{"Dama kier", 12},{"Dama pik", 12}, {"Dama karo", 12}, {"Dama trefl", 12},
{"Król kier", 13},{"Król pik", 13}, {"Król karo", 13}, {"Król trefl", 13},
{"As kier", 14},{"As pik", 14}, {"As karo", 14}, {"As trefl", 14},};
vector<int> deck_old = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
vector<Card> active_cards = {};

int choice;
Card card_in_play;
Card dealt_card;
int score;
int active_deck_size;

bool lost = false;
bool playing = true;

Card dealCard(vector<Card>& vec, int n) {
    swap(vec[n], vec.back());
    Card card = vec.back();
    vec.pop_back();

    return card;
}

int main() {
    while (playing) {
        lost = false;
        cout << "Witaj w High-Low! Wybierz 1. by zagrać, wybierz 2. by wyjść." << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                while (!lost) {
                    if (active_cards.empty()) { // fix!!
                        active_cards = deck;
                        active_deck_size = 52;
                        cout << "Przetasowano talię" << endl;

                        card_in_play = dealCard(active_cards, rand() % active_deck_size);
                        active_deck_size--;
                    }

                    cout << "Twoja karta: " << card_in_play.name << endl;
                    invalid_input:
                    cout << "Jak obstawiasz? (1. jeżeli wyżej, 2. jeżeli niżej)" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            dealt_card = dealCard(active_cards, rand() % active_deck_size);
                            active_deck_size--;
                            cout << "Następna karta to: " << dealt_card.name << endl;

                            if (dealt_card.value == card_in_play.value) {
                                cout << "Remis! Bez punktów" << endl;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card.value > card_in_play.value) {
                                cout << "Zdobywasz 1 punkt!" << endl;
                                score++;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card.value < card_in_play.value) {
                                cout << "Przegrywasz! Twój wynik to: " << score << " punktów" << endl;
                                lost = true;
                                break;
                            }

                        case 2:
                            dealt_card = dealCard(active_cards, rand() % active_deck_size);
                            active_deck_size--;
                            cout << "Następna karta to: " << dealt_card.name << endl;

                            if (dealt_card.value == card_in_play.value) {
                                cout << "Remis! Bez punktów" << endl;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card.value < card_in_play.value) {
                                cout << "Zdobywasz 1 punkt!" << endl;
                                score++;
                                card_in_play = dealt_card;
                                break;
                            }
                            if (dealt_card.value > card_in_play.value) {
                                cout << "Przegrywasz! Twój wynik to: " << score << " punktów" << endl;
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
