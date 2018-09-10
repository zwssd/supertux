//  SuperTux
//  Copyright (C) 2003 Tobias Glaesser <tobi.web@gmx.de>
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "supertux/resources.hpp"

#include "gui/mousecursor.hpp"
#include "supertux/globals.hpp"
#include "video/bitmap_font.hpp"
#include "video/font.hpp"
#include "video/surface.hpp"
#include "video/ttf_font.hpp"

std::unique_ptr<MouseCursor> Resources::mouse_cursor;

FontPtr Resources::console_font;
FontPtr Resources::fixed_font;
FontPtr Resources::normal_font;
FontPtr Resources::small_font;
FontPtr Resources::big_font;

SurfacePtr Resources::checkbox;
SurfacePtr Resources::checkbox_checked;
SurfacePtr Resources::back;
SurfacePtr Resources::arrow_left;
SurfacePtr Resources::arrow_right;
SurfacePtr Resources::no_tile;

void
Resources::load()
{
  // Load the mouse-cursor
  mouse_cursor.reset(new MouseCursor("images/engine/menu/mousecursor.png",
                                     "images/engine/menu/mousecursor-click.png",
                                     "images/engine/menu/mousecursor-link.png"));
  MouseCursor::set_current(mouse_cursor.get());

  if (g_use_bitmap_fonts)
  {
    console_font.reset(new BitmapFont(BitmapFont::FIXED, "fonts/andale12.stf", 1));
    fixed_font.reset(new BitmapFont(BitmapFont::FIXED, "fonts/white.stf"));
    normal_font.reset(new BitmapFont(BitmapFont::VARIABLE, "fonts/white.stf"));
    small_font.reset(new BitmapFont(BitmapFont::VARIABLE, "fonts/white-small.stf", 1));
    big_font.reset(new BitmapFont(BitmapFont::VARIABLE, "fonts/white-big.stf", 3));
  }
  else
  {
    console_font.reset(new TTFFont("fonts/SuperTux-Medium.ttf", 12, 1.25f, 0, 0));
    fixed_font.reset(new TTFFont("fonts/SuperTux-Medium.ttf", 18, 1.25f, 0, 0));
    normal_font.reset(new TTFFont("fonts/SuperTux-Medium.ttf", 18, 1.25f, 2, 1));
    small_font.reset(new TTFFont("fonts/SuperTux-Medium.ttf", 10, 1.25f, 2, 1));
    big_font.reset(new TTFFont("fonts/SuperTux-Medium.ttf", 22, 1.25f, 2, 1));
  }

  /* Load menu images */
  checkbox = Surface::from_file("images/engine/menu/checkbox-unchecked.png");
  checkbox_checked = Surface::from_file("images/engine/menu/checkbox-checked.png");
  back = Surface::from_file("images/engine/menu/arrow-back.png");
  arrow_left = Surface::from_file("images/engine/menu/arrow-left.png");
  arrow_right = Surface::from_file("images/engine/menu/arrow-right.png");
  no_tile = Surface::from_file("images/tiles/auxiliary/notile.png");
}

void
Resources::unload()
{
  // Free menu images
  no_tile.reset();
  checkbox.reset();
  checkbox_checked.reset();
  back.reset();
  arrow_left.reset();
  arrow_right.reset();

  // Free global images:
  console_font.reset();
  fixed_font.reset();
  normal_font.reset();
  small_font.reset();
  big_font.reset();

  mouse_cursor.reset();
}

Resources::Resources()
{
  load();
}

Resources::~Resources()
{
  unload();
}

/* EOF */
