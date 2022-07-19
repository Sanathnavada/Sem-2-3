'''
note to self:
An instance attribute is a Python variable belonging to only one object. It is only
accessible in the scope of the object and it is defined inside the constructor function of a class. For example, init_(self,..).

A class attribute is a Python Variable that belongs to a class rather than a particular
object. This is shared between all other objects of the same class and is defined outside the
constructor function_init__(self,...), of the class.'''

#SAMPLE PYTHON CODE FOR A  BLACKJACK GAME

import random
round = 0
current_value=0
borrows = 0
borrowed_chips = 0

suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs') #tuple
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace') #tuple
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10,
         'Queen':10, 'King':10, 'Ace':11} #dictionary were u pass in the rank and u get back its numerical value


class Card:

    def __init__(self,suit,rank):
        self.suit = suit
        self.rank = rank
        
    def __str__(self):
        return self.rank + ' of ' + self.suit
        
        
class Deck:
    
    def __init__(self):
        self.deck = []  #  empty list
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit,rank))       
    
    def __str__(self):
        deck_comp = ''                                    # start with an empty string
        for car in self.deck:
            deck_comp += '\n ' + car.__str__()    #here car (object) is of type Card hence the class attribute __str__ is accessed
                                                  #and the print statement is appended to deckcomp 
        return 'The deck has:' + deck_comp       # deckcomp is one giant string.
        
        '''
        if you were referring to the class, you would have to use a capital C, but that code is not using the class.
        The deck is a list of card objects, so the loop variable, card, is a Card object,
        and __str__ is an instance method that must be called on an object, not the class.
        You wouldn't have to use car as the variable name -- no matter what name you use,
        it would still be a Card object since that is what the deck contains.
        '''
    def shuffle(self):
        random.shuffle(self.deck)
        
    def deal(self):
        single_card = self.deck.pop(0)
        return single_card
        
        

class Hand:
    
    def __init__(self):
        self.cards = [] 
        self.value = 0   
        self.aces = 0    
    
    def add_card(self,card):
        self.cards.append(card)
        self.value += values[card.rank]   #card is of type Card hence card.rank(rank = inst attri of card) returns rank no in string which when passed to values returns a number
        if card.rank == 'Ace':
            self.aces += 1  # add to self.aces
    
    def adjust_for_ace(self):
        while self.value > 21 and self.aces: #here even tho no condition is provided for self.aces it automatically assumes 1 as true and 0 as false
            self.value -= 10
            self.aces -= 1 

class Chips:
    
    def __init__(self):
        if round != 0:
            self.total = current_value
            self.bet = 0 
        else:    
            self.total = 100  # This can be set to a default value or supplied by a user input
            self.bet = 0
        
    def win_bet(self):
        self.total += self.bet
    
    def lose_bet(self):
        self.total -= self.bet
        
def borrow(chips):
    if(chips.total ==0):
        global borrows
        borrows = 1
        print("you've run out of money!.Remember you can only borrow once and if u loose it all you're not allowed to play again")
        while True:
            try:
                chips.total = int (input('How many chips would you like to borrow '))
            except ValueError:
                print('Sorry, must be a integer ')
            else:
                if chips.total > 100:
                    print('Sorry you cannot borrow more than 100 ')
                else:
                    
                    break
    else:
        pass

def payback(chips,borrowed_chips,borrows):
    if chips.total > borrowed_chips:
        chips.total = chips.total-borrowed_chips
        
        print("returning the chips that is owed, your total standings currently is = ",chips.total)
        return 0
    else:
        return borrows



def take_bet(chips):
    '''
    takebet is not a class . here chips is object of Chips class hence contians all the attributes of that class
    hence total attribute( instance attribute) of Chips class can be accessed
    '''
    
    while True:
        try:
            chips.bet = int(input('How many chips would you like to bet? '))
        except ValueError:
            print('Sorry, a bet must be an integer!')
        else:
            if chips.bet > chips.total:
                print("Sorry, your bet can't exceed",chips.total)
            else:
                break

def hit(deck,hand):
    
    hand.add_card(deck.deal()) #thru deck deal a single card is returned back to add_card which is a fn of hand
    hand.adjust_for_ace()
    
    
def hit_or_stand(deck,hand):
    global playing  # to control an upcoming while loop
    
    while True:
        x = input("Would you like to Hit or Stand? Enter 'h' or 's' ")
        
        if x[0].lower() == 'h':
            hit(deck,hand)  

        elif x[0].lower() == 's':
            print("Player stands. Dealer is playing.")
            playing = False

        else:
            print("Sorry, please try again.")
            continue
        break

def show_some(player,dealer):
    print("\nDealer's Hand:")
    print(" <card hidden>")
    print('',dealer.cards[1])  
    print("\nPlayer's Hand:", *player.cards, sep='\n ')
    
'''
in main player name can be anything but here the formal parameter is player
hence it is referenced using player.  & since player is  object of hand 
it contains cards attribute(instance attribute) which is accessed here
'''
    
def show_all(player,dealer):
    print("\nDealer's Hand:", *dealer.cards, sep='\n ')
    print("Dealer's Hand =",dealer.value)               
    print("\nPlayer's Hand:", *player.cards, sep='\n ')    
    print("Player's Hand =",player.value)
    
def player_busts(player,dealer,chips):
    print("Player busts!")
    chips.lose_bet()

def player_wins(player,dealer,chips):
    print("Player wins!")
    chips.win_bet()

def dealer_busts(player,dealer,chips):
    print("Dealer busts!")
    chips.win_bet()
    
def dealer_wins(player,dealer,chips):
    print("Dealer wins!")
    chips.lose_bet()
    
def push(player,dealer):
    print("Dealer and Player tie! It's a push.")

print('Welcome to BlackJack! Get as close to 21 as you can without going over!\n\
    Dealer hits until he reaches 17. Aces count as 1 or 11.')    
while True:  #while loop not for playing variable
    
    playing = True
    
    deck = Deck()
    deck.shuffle()
    
    player_hand = Hand()
    player_hand.add_card(deck.deal())
    player_hand.add_card(deck.deal())
    
    dealer_hand = Hand()
    dealer_hand.add_card(deck.deal())
    dealer_hand.add_card(deck.deal())
            
    
    player_chips = Chips()  #  default value is 100    
    
    # Prompt the Player for their bet
    take_bet(player_chips)
    
    show_some(player_hand,dealer_hand)
    
    while playing:
       
        hit_or_stand(deck,player_hand) 
        show_some(player_hand,dealer_hand)  
        if player_hand.value > 21:                # If player's hand exceeds 21, run player_busts() and break out of loop
            player_busts(player_hand,dealer_hand,player_chips)
            break        


    # If Player hasn't busted, play Dealer's hand until Dealer reaches 17 
    if player_hand.value <= 21:
        
        while dealer_hand.value < 17:
            hit(deck,dealer_hand)    
    
        # Show all cards
        show_all(player_hand,dealer_hand)
        
        # Run different winning scenarios
        if dealer_hand.value > 21:
            dealer_busts(player_hand,dealer_hand,player_chips)

        elif dealer_hand.value > player_hand.value:
            dealer_wins(player_hand,dealer_hand,player_chips)

        elif dealer_hand.value < player_hand.value:
            player_wins(player_hand,dealer_hand,player_chips)

        else:
            push(player_hand,dealer_hand)        
    
    print("\nPlayer's winnings stand at",player_chips.total) 
    current_value=player_chips.total 
    #here similarly player_chips is a object of the class Chips which(player_chips) contains the attributes total
    # and bet(instance attributes - attributes of the object player_chips) and total is accessed here
    
    
    # Ask to play again
    if borrows>= 1:
        borrows = payback(player_chips,borrowed_chips,borrows)
    if borrows == 0:
        new_game = input("Would you like to play another hand? Enter 'y' or 'n' ")
        if new_game[0].lower()=='y':
            print('Starting another round ')
                
        else:
            print('Thanks for playing!')
            break
        
    elif player_chips.total == 0:
        if borrows >= 1:
            print("you've lost all your borrowed money! you are not allowed to play again ")
            break
    else:    
        print('Cannot stop playing until debt is cleared...starting another round ')
    
    round = round +1
    borrow(player_chips)
    if borrows == 1:
        borrows = borrows +1
        borrowed_chips =player_chips.total
    
    current_value=player_chips.total 
    continue
    
    
    



