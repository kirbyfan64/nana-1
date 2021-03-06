/*
 *	A Picture Implementation
 *	Nana C++ Library(http://www.nanapro.org)
 *	Copyright(C) 2003-2015 Jinhao(cnjinhao@hotmail.com)
 *
 *	Distributed under the Boost Software License, Version 1.0. 
 *	(See accompanying file LICENSE_1_0.txt or copy at 
 *	http://www.boost.org/LICENSE_1_0.txt)
 *
 *	@file: nana/gui/widgets/picture.hpp
 *
 *	Used for showing a picture
 */
#ifndef NANA_GUI_WIDGET_PICTURE_HPP
#define NANA_GUI_WIDGET_PICTURE_HPP
#include "widget.hpp"

namespace nana
{
	namespace xpicture
	{
		class picture_drawer: public drawer_trigger
		{
		public:
			picture_drawer();
			void attached(widget_reference, graph_reference)	override;
			void load(const nana::char_t* file);
			void load(const nana::paint::image&);
			void set_shadow_background(const ::nana::color& from, const ::nana::color& to, bool horizontal);
			bool bgstyle(bool is_stretch, nana::arrange, int beg, int end);
		private:
			void refresh(graph_reference)	override;
			void _m_draw_background();
		private:
			widget* widget_;
			nana::paint::graphics* graph_;

			struct
			{
				::nana::color gradual_from;
				::nana::color gradual_to;
				bool	horizontal;
			}bground_;

			struct back_image_tag
			{
				nana::paint::image	image;
				bool is_stretch;
				nana::arrange arg;
				int beg, end;
			}backimg_;

		};
		
	}//end namespace xpicture
       /// Rectangle area for displaying a bitmap file
	class picture
		: public widget_object<category::widget_tag, xpicture::picture_drawer>
	{
	public:
		picture();
		picture(window, bool visible);
		picture(window, const rectangle& = rectangle(), bool visible = true);

		void load(const nana::paint::image&);

        /// Sets the background image style.
		void bgstyle(bool stretchable,    ///< if false the other arguments will be ignored
                      nana::arrange arg,  ///< stretching the image horizontally or vertically
                      int beg,            ///< specify the stretchy area of image.
                      int end             ///< specify the stretchy area of image.
                      );

        /// Fills a gradual-change color in background. If One of colors is invisible or clr_from is equal to clr_to, it draws background in bgcolor.
		void set_gradual_background(const ::nana::color& clr_from, const ::nana::color& clr_to, bool horizontal);
		void transparent(bool);
		bool transparent() const;
	};
}//end namespace nana
#endif
