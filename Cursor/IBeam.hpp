#ifndef OSHGUI_CURSOR_IBEAM_H_
#define OSHGUI_CURSOR_IBEAM_H_

#include "Cursor.hpp"

namespace OSHGui
{
	class IBeamCursor : public Cursor
	{
	public:
		IBeamCursor();
		virtual ~IBeamCursor();
		
	protected:
		virtual void CreateCursor();
	};
}

#endif