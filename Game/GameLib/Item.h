/**
 * @file Item.h
 * @author Blake
 *
 *
 */

#ifndef GAME_ITEM_H
#define GAME_ITEM_H

class Game;

class Item {
private:
    /// The game this item is contained in
    Game *mGame;

    // Item location in the game
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying bug image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this bug
    std::unique_ptr<wxBitmap> mItemBitmap;

    bool mMirror = false;   ///< True mirrors the item image
public:
    virtual ~Item();
    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    // Functions ----

    virtual void Draw(wxDC *dc);

    virtual bool HitTest(int x, int y);

    double DistanceTo(std::shared_ptr<Item> item);

    virtual wxXmlNode* XmlSave(wxXmlNode* node);

    virtual void XmlLoad(wxXmlNode* node);

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}

    /**
     * Get the pointer to the Game object
     * @return Pointer to Game object
     */
    Game *GetGame() { return mGame;  }

    //void SetMirror(bool m);   still need to implement this
protected:
    Item(Game *game, const std::wstring &filename);

};

#endif //GAME_ITEM_H
