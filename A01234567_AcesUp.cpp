/**\file A01234567_AcesUp.cpp
 * \brief Contains the methods that describe the Aces Up game.
 * \author Preston Maness
 *
 */

/*
 * A01234567_AcesUp.cpp
 *
 *  Created on: Jul 5, 2012
 *      Author: preston
 */

#include "A01234567_AcesUp.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

/**
 *
 * \pre stax is an unitialized vector of vectors. The vector representing the deck
 * is thus empty.
 * \post stax is resized to 6 vectors, and the first vector is filled with Card
 * objects that have been shuffled.
 *
 * The constructor resizes \c stax to contain 6 vectors, which
 * will function as the game's deck, four columns, and trash pile.
 * \c stax itself essentially serves as the state machine, storing
 * the state of the game with each iteration of \c gameLoop().
 * the first vector is filled with 52 \c Card objects, and then
 * randomized using the Knuth shuffle.
 *
 */

AcesUp::AcesUp()
{

	/*
	 * Fill the vector of vectors with six vectors. One for the deck, four
	 * for the stacks of cards, and one for trash.
	 *
	 */

	stax.resize(6);

	/*
	 * Initialize the deck.
	 */

	for (int i = 0 ; i < NUM_SUITS ; i++)
	{
		for (int j = 0 ; j < NUM_SUIT_CARDS ; j++)
		{
			Card temp((i*NUM_SUIT_CARDS + j),i,j,true);
			stax[0].push_back(temp);
		}
	}

	/*
	 * Shuffle the deck using Knuth shuffle. Shuffle 3 times.
	 * Every day I'm shufflin...
	 */

	for ( int i = 0 ; i < 3 ; i++)
	{

		for ( int j = DECK_SIZE - 1 ; j > 0 ; j--)
		{
			int k = rand() % j;
			Card temp = stax[0][j];
			stax[0][j] = stax[0][k];
			stax[0][k] = temp;
		}

	}

}

AcesUp::~AcesUp()
{



}

/**
 *
 * \warning This is currently incomplete. It functions, but I am
 * currently looking into refactoring the parseCommand() -> commandFxn()
 * workflow to return booleans rather than be voids that solely
 * operate on \c stax. This will permit indication of whether or not
 * command was successful. This in turn can permit advanced logging of
 * game to disk and statistical analysis.
 *
 * The main loop of the game. this loop is only exited
 * upon a value of "q" for the string \c cmd, at which
 * parseCommand interprets this as a quit command and
 * exits the program.
 *
 *
 */

void AcesUp::gameLoop()
{

	while(true)

	{

	render();

    cout << "Command: ";
    string cmd;
    getline(cin,cmd,'\n');

    parseCommand(cmd);

	}

}

/**
 *
 * Spits out ascii art intro and gives a guide for the commands
 * that control the game. Specifically, the commands are:
 * 'q' : quit
 * 'd' : deal
 * 'rA' : remove column A
 * 'mAB' : move column A to B
 *
 */

void AcesUp::intro()
{

	system("clear");

	cout << "===============================================================================" << endl;
	cout << "		  ___                  _   _       " << endl;
	cout << "		 / _ \\                | | | |      " << endl;
	cout << "		/ /_\\ \\ ___ ___  ___  | | | |_ __  " << endl;
	cout << "		|  _  |/ __/ _ \\/ __| | | | | '_ \\ " << endl;
	cout << "		| | | | (_|  __/\\__ \\ | |_| | |_) |" << endl;
	cout << "		\\_| |_/\\___\\___||___/  \\___/| .__/ " << endl;
	cout << "		                            | |    " << endl;
	cout << "		                            |_|    " << endl << endl;
	cout << "Welcome to this CLI version of the Solitaire-based card game known \n"
			"as Aces Up. It is assumed that the player already understands the rules.\n";
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << endl;
	cout <<	"There are a few commands, listed below:\n\n" << left
			<< setw(8) << "Quit: " << setw(15) << " 'q' " << setw(10) << " immediately exit to shell \n"
			<< setw(8) << "Move: " << setw(15) << " 'm(from)(to)' " << setw(10) << " e.g. \'m12\' moves topcard on stack 1 onto empty stack 2.\n"
			<< setw(8) << "Remove: " << setw(15) << " 'r(from)' " << setw(10) << " e.g. \'r3\' removes the topcard from stack 3. \n"
			<< setw(8) << "Deal: " << setw(15) << " 'd' " << setw(10) << " will deal new layer of cards onto stacks."

		<< endl << endl;

	cout << "Press enter to continue: " ;
	cin.get();
}

/**
 *
 * \pre the string \c input isn't parsed.
 * \post after parsing, either a game command is executed, which may
 * or may not succeed, or a message is sent to the user stating that
 * input is malformed.
 *
 * The parseCommand function only ensures that a command is well-formed. It
 * does not check state to see if the command is possible. That is handled by the
 * individual methods for each command.
 *
 * \param[in] input the string that is parsed from the \c gameLoop() function.
 */

void AcesUp::parseCommand(string input)
{

		/* Quit */
		if(input[0] == 'q')
		{
			cout << endl << "QUITTING NOW!" << endl;
			exit(0); /* I could probably code in a more graceful way to handle quitting. */
		}

		/* Move */
		else
		if(input[0] == 'm')
		{

			int from = strtol((input.substr(1,1)).c_str(),NULL,10);
			int to = strtol((input.substr(2,1)).c_str(),NULL,10);

			/* To avoid confusion in the event of input like 'm123', force strict
			 * matching of m## and nothing else */
			bool strict = false;
			if(input.length() >= 4)
			{
				strict = true;
			}

			if((from < 5) && (from > 0) && (to < 5) && (to > 0) && !strict)
			{
				move(from,to);
			}
			else
			{
				cout << "Move command malformed. Try again." << endl;
			}

		}

		/* Remove */
		else
		if(input[0] == 'r')
		{
			int column = strtol((input.substr(1,1)).c_str(),NULL,10);

			/* To avoid confusion in the event of input like 'r12', force strict
			 * matching of r# and nothing else
			 */
			bool strict = false;
			if(input.length() >= 3)
			{
				strict = true;
			}

			if((column < 5) && (column > 0) && !strict)
			{
				remove(column);
			}
			else
			{
				cout << "Remove command malformed. Try again." << endl;
			}

		}

		/* Deal */
		else
		if(input[0] == 'd')
		{
			deal();
		}
		else
		{
			cout << "Unrecognized command. Try again." << endl;
		}

}

/**
 *
 * \warning I'm investigating any possible ways to shorten the command logic.
 * Particularly by removing \c suitvals[] and checking \c stax
 * directly when necessary.
 *
 * \pre user input was parsed and determined to be a deal command.
 * \c stax is not yet updated.
 * \post if a deal command is possible, stax is updated. Otherwise,
 * user is informed that the deal command isn't possible and prompts
 * for user to press enter to continue loop.
 *
 * The deal command must check for certain conditions:
 *
 * 1.) Each topcard's suit is unique. Done with temporary suitvals[]
 * integer array that grabs each card object's integer suit value. A
 * linear search is then done to detect matches. Spaces are permitted
 * and do not count as "matches" against themselves or others.
 *
 * 2.) Deck is not empty. If so, alert player to quit game.
 *
 */

void AcesUp::deal()
{

	/* You can only deal if the topcard in each column is of a different suit.
	 * Empty spaces are also allowed. So, make sure to check that the column isn't empty
	 * prior to checking the suit of the topcard.
	 */

	/* -1 - indicates an empty column.
	 * S - 0
	 * H - 1
	 * D - 2
	 * C - 3
	 */

	int suitvals[] = {-1,-1,-1,-1};

	if(!stax[1].empty())
	{
		suitvals[0] = (stax[1].back()).getSuitValue();
	}

	if(!stax[2].empty())
	{
		suitvals[1] = (stax[2].back()).getSuitValue();
	}

	if(!stax[3].empty())
	{
		suitvals[2] = (stax[3].back()).getSuitValue();
	}

	if(!stax[4].empty())
	{
		suitvals[3] = (stax[4].back()).getSuitValue();
	}

	/* Now, suitvals[] has been fully filled with integer suit values.
	 * let's make sure there are no matching suit values so that we can deal.
	 * the boolean value flag defaults to true, and permits the dealing action.
	 */

	bool flag = true;

	/* Begin scan for matching suits */
	for ( int i = 0 ; i < 3 ; i++)
	{

		/* If it's an empty space, no sense comparing it */
		if( suitvals[i] == -1)
		{
			continue;
		}

		/* Check for matches */
		for ( int j = i+1 ; j < 4 ; j++)
		{
			if (suitvals[i] == suitvals[j])
			{
				flag = false;
				break;
			}
		}

		/* If we find that two columns' topcards have matching suits
		 * then there is no sense in checking further.
		 */
		if(flag == false)
		{
			break;
		}

	}

	/* In the event that the deck is empty, inform the player. */
	if(stax[0].empty())
	{
		cout << "Deck is empty. " << endl;
		cout << "Please press enter, and then use 'q' to quit: ";
		cin.get();
	}

	/* All checks passed. Deal cards onto the columns. */
	else
	if (flag)

	{

	stax[1].push_back(stax[0].back());
	stax[0].pop_back();
	stax[2].push_back(stax[0].back());
	stax[0].pop_back();
	stax[3].push_back(stax[0].back());
	stax[0].pop_back();
	stax[4].push_back(stax[0].back());
	stax[0].pop_back();

	}

	/* The current method of handling failed commands like this is hacky.
	 * I should make the action of GETTING a command atomic, and not
	 * directly tied into the gameLoop() above.
	 */

	/* One or more checks failed. No change in state. */
	else
	{
		cout << "Cannot deal yet. At least two topcards have same suit." << endl;
		cout << "Press enter to continue: " ;
		cin.get();
	}
}

/**
 *
 * \warning I'm investigating any possible ways to shorten the command logic.
 * Particularly by removing \c suitvals[] and \c facevals[] and checking \c stax
 * directly when necessary.
 *
 * \pre user input was parsed and determined to be a remove command.
 * \post If it is possible to remove the topcard of \c column, then \c stax is
 * updated appropriately. Otherwise, user is informed that the remove isn't
 * possible.
 *
 * From a logical standpoint, the remove command is the most intensive. Many cases
 * must be checked for:
 *
 * 1.) Ensure there is at least one other column (besides \c column) whose topcard is of
 * the same suit as \c column's topcard. A scan of the suits is performed as in
 * the deal function with a temporary suitvals[] integer array. Further,
 * \c columnsuitval is used to mark the suit of the column the user requests to
 * remove.
 *
 * 2.) Ensure that the column the user requests to remove is not the highest valued
 * topcard of that suit. This is done with a temporary facevals[] integer array. A
 * linear search is conducted that checks for matching suits from suitvals[]
 * that are also of the suit of the requested column's topcard, \c columnsuitval. If
 * a match is found, then that element of facevals[] gets the card object's face value.
 * Otherwise, it remains as -1.
 *
 * 3.) Once suitvals[] and facevals[] are initialized, check to see if there are no
 * matches at all. This can be done by examining the content of facevals[]. Should all
 * elements be negative one, then no matches were found.
 *
 * 4.) Once suitvals[] and facevals[] are initialized, ensure that \c column is not
 * the highest valued topcard of its suit. Perform a linear search on the fully initialized
 * facevals[] and if the index with the highest value (plus one) is also that of \c column,
 * then do not remove \c column.
 *
 * 5.) Ensure that user does not attempt to remove an empty space. Can use the suitvals[]
 * array for this case (if the element is -1, then it is an empty space).
 *
 * \param[in] column specifies the column of the topcard the user wishes to remove.
 */

void AcesUp::remove(int column)
{

	/* You can only remove a card if at least two topcards are of the same suit,
	 * AND you aren't removing the highest-valued card (ace is high).
	 * Once again, we start by checking for empty spaces.
	 */

	/* -1 - indicates an empty column.
	 * S - 0
	 * H - 1
	 * D - 2
	 * C - 3
	 */

	int suitvals[] = {-1,-1,-1,-1};

	if(!stax[1].empty())
	{
		suitvals[0] = (stax[1].back()).getSuitValue();
	}

	if(!stax[2].empty())
	{
		suitvals[1] = (stax[2].back()).getSuitValue();
	}

	if(!stax[3].empty())
	{
		suitvals[2] = (stax[3].back()).getSuitValue();
	}

	if(!stax[4].empty())
	{
		suitvals[3] = (stax[4].back()).getSuitValue();
	}

	/* Now, suitvals[] has been fully filled with integer suit values.
	 * Our next action is to find the matching suits, and figure out
	 * their face values. We use columnsuitval to make sure we only find
	 * matches of the suit of the requested column.
	 */

	int facevals[] = {-1,-1,-1,-1};
	int columnsuitval = stax[column].back().getSuitValue();

	for ( int i = 0 ; i < 3 ; i++)
	{

		/* If it's an empty space, no sense comparing it */
		if( suitvals[i] == -1)
		{
			continue;
		}

		/* Check for matches OF THE SUIT OF THE COLUMN REQUESTED */
		/* I.e., if we're trying to remove a two of spades, we don't want
		 * subsequent checks further down to pass just because columns
		 * two and three were both diamonds.
		 */
		for ( int j = i+1 ; j < 4 ; j++)
		{
			if (suitvals[i] == suitvals[j] && suitvals[i] == columnsuitval  && suitvals[j] == columnsuitval)
			{
				facevals[i] = stax[i+1].back().getFaceValue();
				facevals[j] = stax[j+1].back().getFaceValue();
			}
		}

	}

	/*
	 * As of now, facevals[] has been fully initialized
	 * with the face values of any matching-suit topcards.
	 * Recall from above that elements of facevals[]
	 * only changed from -1 to their faceval if they were matching suits,
	 * AND that suit was the same as the suit from the column requested.
	 * Consequently, facevals[] should be filled with "-1" entries
	 * UNLESS there are matches.
	 */

	/* Check if there were any matches. If not, then the card is the
	 * only suit of its type in the top layer (or it's an empty space).
	 * Don't remove it.
	 */
	int count = 0;
	bool solo = false;

	for(int i = 0 ; i < 4 ; i++)
	{
		if (facevals[i] < 0)
		{
			count++;
		}
	}
	if (count == 4)
	{
		solo = true;
	}

	/*
	 * We need to know which array element is the highest, so that
	 * we don't remove it (doing so is against the rules of the game).
	 * The boolean 'flag' defaults to false. It is only set to true if
	 * the column isn't the only suit of its kind on the top layer, AND
	 * upon further inspection it isn't the HIGHEST valued card of its
	 * suit on the top layer.
	 */

	bool flag = false;

	/* If we already know it's the only card of its suit, no sense further
	 * comparing anything.
	 */
	if(!solo)
	{
		int highest = 0;

		for ( int i = 1 ; i < 4 ; i++)
		{
			if(facevals[i] > facevals[highest])
			{
				highest = i;
			}
		}

		if((highest+1) != column)
		{
			flag = true;
		}
	}

	/* At this point we can finally determine whether or not to remove the card. */

	/* If it's not solo AND isn't the highest val, remove it! */
	if(flag && !solo)
	{
		stax[5].push_back(stax[column].back());
		stax[column].pop_back();
	}

	/* Let's distinguish at this point between removing an empty space,
	 * and trying to remove the only card (or highest card) of the requested
	 * suit. We check the suitvals[] array to determine if column is an empty
	 * space.
	 */
	else
	if(suitvals[column-1] == -1)
	{
		cout << "What makes you think you can remove an empty space?" << endl;
		cout << "Please press enter: ";
		cin.get();
	}

	/* Finally, if the requested column ISN'T an empty space, then it must either
	 * be the only flag of it's suit in the top layer OR the highest valued
	 * face of its suit in the top layer. Output this to user and wait for input.
	 */
	else
	{
		cout << "You cannot remove the highest-valued card of the suit. " << endl;
		cout << "Please press enter: ";
		cin.get();
	}

}

/**
 *
 * \pre user input was parsed and determined to be a move command.
 * \post Assuming from isn't empty and to is, \c stax is updated with the
 * move command. Otherwise, user is informed that the move command is invalid.
 *
 * The only requirements for a move command are that the \c to column is
 * empty and the \c from column isn't.
 *
 * \param[in] from column whose topcard the user wishes to move.
 * \param[in] to column that user wants \c from 's topcard moved to.
 */

void AcesUp::move(int from , int to)
{

	/* So long as the to column is empty and from column isn't, you can move.  */

	if(stax[to].empty() && !stax[from].empty())
	{
		stax[to].push_back(stax[from].back());
		stax[from].pop_back();
	}
	else
	{
		cout << "Invalid move command. " << endl;
		cout << "Please press enter: " ;
		cin.get();
	}

}

/* The renderer basically processes output line by line. It analyzes the current state of the
 * stax variable and outputs the state given by that analysis (which cards in which stacks, etc).
 * Since we render based on the state of the stax variable, the rendering is independent of any particular
 * user command. */

/**
 *
 * \pre The screen is filled with the state of \c stax prior to the gameLoop()'s
 * parseCommand().
 * \post The screen is updated to reflect changes in state of \c stax due to
 * parseCommand() and resulting command function logic. There may not be any visible
 * change in rendering if, for example, the user provides a malformed command or
 * an illegal command request.
 *
 * This renderer basically processes output line by line. It analyzes the state of
 * \stax after parseCommand() and company have done their thing, and output's that
 * state to the screen. Since rendering is based on \c stax, it is independent
 * of any particular command.
 *
 * \c layer tracks the layer of cards being displayed. The size of each column
 * is checked against this. For example, if we are on layer 3 (fourth card),
 * and only one column has four cards, then the other columns will fail the
 * stax[i].size() > layer check, and simply output a tab rather than try to
 * access stax[i][layer].
 *
 * \c count tracks how many columns are completely displayed in each \c layer
 * iteration. The idea is that so long as there is still at least one column
 * to render, \c count does not reach 4. Once \c layer reaches a value where
 * stax[i].size() > layer fails for all columns, then \c count == 4 and we
 * are "done" rendering columns.
 *
 * \c trash is the size of the trash. Incidentally, it also serves as the
 * index for the trash vector. This renderer will output at most twelve
 * elements from stax[5] per \c layer iteration, decrementing \c trash with
 * every output. The renderer is finished outputing the trash pile once
 * \c trash reaches 0.
 *
 * Consequently, when \c count == 4 and \c trash == 0, we are finished
 * rendering both the columns and the trash pile, and can return to
 * gameLoop().
 *
 */

void AcesUp::render()
{

	bool finished = false;
	unsigned long layer = 0; /* Tracks which "layer" of cards is being displayed */
	int trash = stax[5].size();

	system("clear"); /* I know using "system" calls is incredibly bad practice from a security standpoint,
						but I'll come back and reimplement the functionality later */
					 /*
					  *
										{o,o}
										|)__)
										-”-”-
										O RLY?
					  *
					  */

	cout << "1: " << "\t" << "2: " << "\t" << "3: " << "\t" << "4: " << "\t" << "Trash: " << endl << endl;

	while( !finished )
	{

		/* Tracks number of stacks completely displayed. Resets after each iteration.
		 * The idea is that once EVERY column has been FULLY displayed (count == 4)
		 * we can then stop rendering lines (so long as trash is completely displayed
		 * too). */
		int count = 0;

		/* Display card stacks */

		for (int i = 1 ; i < 5 ;i++)
		{
			if( stax[i].size() > layer )
			{
				cout << stax[i][layer].getFaceSymbol() << stax[i][layer].getSuitSymbol() << "\t";
			}
			else
			{
				cout << "\t";
				count++;
			}
		}

		layer++;

		/* Display garbage off to the right */

		int i = trash - 1; /* since trash is based off of the vector::size() function,
		 	 	 	 	 	  we want to ensure we call the right index */

		int j = trash -12; /* We also only want to display 12 cards on any given row of
						      screen output */

		for( ; i > j && trash != 0 ; i--)
		{
			cout << stax[5][i].getFaceSymbol() << stax[5][i].getSuitSymbol() << ",";
			trash--;
		}

		/* we have iterated through all cards in each play stack and the trash. Stop display loop. */
		if(count == 4 && trash == 0)
		{
			finished = true;
		}

		cout << endl;
	}

}


