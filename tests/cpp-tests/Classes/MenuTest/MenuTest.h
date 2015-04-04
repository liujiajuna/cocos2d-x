/****************************************************************************
 Copyright (c) 2012 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef _MENU_TEST_H_
#define _MENU_TEST_H_

////----#include "cocos2d.h"
#include "../BaseTest.h"

DEFINE_TEST_SUITE(MenuTests);

class MenuTest : public TestCase
{
public:
    CREATE_FUNC(MenuTest);

    virtual bool init() override;
};

class MenuLayerMainMenu : public Layer
{
protected:
    MenuItem*    _disabledItem;
    EventListenerTouchOneByOne* _touchListener;

public:
    MenuLayerMainMenu();
    ~MenuLayerMainMenu();

public:
    bool onTouchBegan(Touch *touch, Event * event);
    void onTouchEnded(Touch *touch, Event * event);
    void onTouchCancelled(Touch *touch, Event * event);
    void onTouchMoved(Touch *touch, Event * event);

    void allowTouches(float dt);
    void menuCallback(Ref* sender);
    void menuCallbackConfig(Ref* sender);
    void menuCallbackDisabled(Ref* sender);
    void menuCallback2(Ref* sender);
    void menuCallbackPriorityTest(Ref* sender);
    void menuCallbackBugsTest(Ref *pSender);
    void onQuit(Ref* sender);
    void menuMovingCallback(Ref *pSender);

    //CREATE_NODE(MenuLayer1);
};

class MenuLayer2 : public Layer
{
protected:
    Vec2        _centeredMenu;
    bool                _alignedH; 

    void alignMenusH();
    void alignMenusV();

public:
    MenuLayer2();
    ~MenuLayer2();

    void menuCallback(Ref* sender);
    void menuCallbackOpacity(Ref* sender);
    void menuCallbackAlign(Ref* sender);

    //CREATE_NODE(MenuLayer2);
};

class MenuLayer3 : public Layer
{
protected:
    MenuItem*    _disabledItem;

public:
    MenuLayer3();
    ~MenuLayer3();
};

class MenuLayer4 : public Layer
{
public:
    MenuLayer4();
    ~MenuLayer4();

    void menuCallback(Ref* sender);
    void backCallback(Ref* sender);
};

class BugsTest : public Layer
{
public:
    BugsTest();
    
    void issue1410MenuCallback(Ref *pSender);
    void issue1410v2MenuCallback(Ref *pSender);
    void backMenuCallback(Ref *pSender);
};

class RemoveMenuItemWhenMove : public Layer
{
public:
    RemoveMenuItemWhenMove();
    ~RemoveMenuItemWhenMove();
    bool onTouchBegan(Touch  *touch, Event  *event);
    void onTouchMoved(Touch  *touch, Event  *event);
    
    void goBack(Ref *pSender);
    
private:
    MenuItemFont *item;
    EventListenerTouchOneByOne* _touchListener;
};

#endif
