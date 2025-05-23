/*
 * CMessageBoxVort.h
 *
 *  Created on: 30.03.2011
 *      Author: gerstrong
 */

#ifndef CMESSAGEBOXVORT_H_
#define CMESSAGEBOXVORT_H_

#include "dialog/CMessageBox.h"

class CMessageBoxVort : public CMessageBox
{
public:
    CMessageBoxVort(const std::string& Text,
                    const bool lower = false,
                    const bool keymsg = false,
                    const bool vorticonBorders = true);

    void initVorticonBackground();


	/**
	 * \brief This will add an extra tile to the message box. Mostly used by the dialog "Ship missing" in Keen 1
	 */
    void addTileAt(const Uint16 tile, const Uint16 x, const Uint16 y);

};

#endif /* CMESSAGEBOXVORT_H_ */
