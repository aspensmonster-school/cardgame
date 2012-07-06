/*
 * A01234567_AcesUp.h
 *
 *  Created on: Jul 5, 2012
 *      Author: preston
 */

#ifndef A01234567_ACESUP_H_
#define A01234567_ACESUP_H_

#include "A01234567_Card.h"
#include <vector>

using namespace std;

class AcesUp

{

private:

	vector< vector<Card> > stax;

public:

	AcesUp();

	virtual ~AcesUp();

};

#endif /* A01234567_ACESUP_H_ */
