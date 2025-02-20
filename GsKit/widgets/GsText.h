/*
 * GsText.h
 *
 *  Created on: 30.10.2011
 *      Author: gerstrong
 *
 *  This is the text control for our new GUI
 */

#ifndef GsText_H_
#define GsText_H_

#include <vector>
#include <string>
#include <map>
#include <memory>

#include "GsWidget.h"

#include <graphics/GsSurface.h>

#include <graphics/GsTrueTypeFont.h>

#include <base/interface/property_tree/property_tree.h>

class GsText : public GsWidget
{
public:

    GsText(const std::string &text,
             const GsRect<float> &rect);

    GsText(const std::string &text,
             const GsRect<float> &rect,
             const int fontId);

    virtual void setText(const std::string& text);

    void setTextColor(const GsColor &color);

    virtual void processLogic();
    virtual void processRender(const GsRect<float> &RectDispCoordFloat);

    /**
     * @brief processRender
     * @param backRect or content is stuff hidden behind front rect
     * @param frontRect or viewRect is the parent rect or what mostly is seen by the user
     */
    virtual void processRender(const GsRect<float> &backRect,
                               const GsRect<float> &frontRect);

    // Defines in character units how tall and wide the entire text is.
    GsRect<unsigned int> mTextDim;

    void enableCenteringH(const bool value)
    {
        mHCentered = value;
    }

    void setFontId(const int fontId)
    {
        mFontId = fontId;
    }

    int getFontId() const
    {
        return mFontId;
    }

    auto getBlitRect() -> auto
    {
        return mTextBlitRect;
    }


protected:

    void updateTTFTextSfc(const GsRect<float> &displayRect);

    void updateLegacyTextSfc(const GsRect<float> &displayRect);

    std::vector<std::string> mTextVec;

    std::map< GsColor, std::vector<GsSurface> > mTextSfcVecByColor;

    GsColor mTextColor;

private:

    /// Automatic horizontal scrolling in case the text is too big
    float mScrollPosMax = 0.0f;
    float mScrollPos = 0.0f;
    float mScrollVel = 0.3f;

    GsTrueTypeFont mTrueTypeFont;

    std::string mText;
    int mFontSize = 0;
    bool mTextChanged = true;

    bool mHCentered = true;

    enum class ScrollDir
    {
        NONE,
        LEFT,
        RIGHT
    } mScrollDir = ScrollDir::NONE;

    int mFontId = -1;

    // Temporary calculated rect used externally
    // (Useful for blinking cursors)
    GsRect<float> mTextBlitRect;
};

std::shared_ptr<GsText> createTextFrom(const GsKit::ptree &node);

#endif /* GsText_H_ */
