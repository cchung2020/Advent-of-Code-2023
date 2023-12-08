#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <ranges>
#include <array>

using namespace std;
using namespace views;

struct PokerHand {
	enum class PokerType {
		HighCard,
		OnePair,
		TwoPair,
		ThreeKind,
		FullHouse,
		FourKind,
		FiveKind
	};
	enum class CardVal {
		Two,Three,Four,Five,Six,Sev,Eight,Nine,
		T,J,Q,K,A
	};

	int bid;
	array<CardVal, 5> cardHand;
	string hand;
	PokerType type;
};

std::istream& operator>>(std::istream& in, PokerHand& pokerHand) {
	using enum PokerHand::PokerType;
	using CardVal = PokerHand::CardVal;

	in >> pokerHand.hand >> pokerHand.bid;

	for (auto [i, c] : pokerHand.hand | enumerate) {
		if (c == 'A')      pokerHand.cardHand[i] = CardVal::A;
		else if (c == 'K') pokerHand.cardHand[i] = CardVal::K;
		else if (c == 'Q') pokerHand.cardHand[i] = CardVal::Q;
		else if (c == 'J') pokerHand.cardHand[i] = CardVal::J;
		else if (c == 'T') pokerHand.cardHand[i] = CardVal::T;
		else if (c == '2') pokerHand.cardHand[i] = CardVal::Two;
		else if (c == '3') pokerHand.cardHand[i] = CardVal::Three;
		else if (c == '4') pokerHand.cardHand[i] = CardVal::Four;
		else if (c == '5') pokerHand.cardHand[i] = CardVal::Five;
		else if (c == '6') pokerHand.cardHand[i] = CardVal::Six;
		else if (c == '7') pokerHand.cardHand[i] = CardVal::Sev;
		else if (c == '8') pokerHand.cardHand[i] = CardVal::Eight;
		else if (c == '9') pokerHand.cardHand[i] = CardVal::Nine;
	}

	bool five_kind = ranges::all_of(pokerHand.hand, [pokerHand](auto c) {
		return c == pokerHand.hand[0];
	});

	bool four_kind = false;
	for (auto card : pokerHand.hand) {
		if (ranges::count_if(pokerHand.hand, [card](auto c) { return c == card; }) == 4) {
			four_kind = true;
		}
	}

	bool three_kind = false;
	for (auto card : pokerHand.hand) {
		if (ranges::count_if(pokerHand.hand, [card](auto c) { return c == card; }) == 3) {
			three_kind = true;
		}
	}

	bool full_house = false;
	if (three_kind) {
		set<char> unique_cards(pokerHand.hand.begin(), pokerHand.hand.end());
		full_house = unique_cards.size() == 2;
	}

	bool one_pair = false;
	for (auto card : pokerHand.hand) {
		auto card_count = ranges::count_if(pokerHand.hand, [card](auto c) { return c == card; });

		if (card_count == 2) {
			one_pair = true;
		}
	}

	bool two_pair = false;
	if (one_pair) {
		set<char> unique_cards(pokerHand.hand.begin(), pokerHand.hand.end());
		two_pair = unique_cards.size() == 3;
	}

	if (five_kind) pokerHand.type =       FiveKind;
	else if (four_kind) pokerHand.type =  FourKind;
	else if (full_house) pokerHand.type = FullHouse;
	else if (three_kind) pokerHand.type = ThreeKind;
	else if (two_pair) pokerHand.type =   TwoPair;
	else if (one_pair) pokerHand.type =   OnePair;
	else pokerHand.type =                 HighCard;

	return in;
}

bool operator<(PokerHand& h1, PokerHand& h2) {
	if (h1.type < h2.type) return true;
	if (h1.type > h2.type) return false;

	for (int i = 0; i < h1.hand.size(); i++) {
		if (h1.cardHand[i] < h2.cardHand[i]) return true;
		if (h1.cardHand[i] > h2.cardHand[i]) return false;
	}

	return false;
}

void day7a() {
	vector<PokerHand> hands;

	string line;
	PokerHand hand;
	while (cin >> hand) {
		hands.push_back(hand);
	}

	ranges::sort(hands, [](auto& a, auto& b) { return a < b; });

	int winnings = 0;
	for (int i = 0; i < hands.size(); i++) {
		winnings += hands[i].bid * (i + 1);
	}

	println("{}", winnings);
}
