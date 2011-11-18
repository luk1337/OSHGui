#ifndef OSHGUI_APPLICATION_HPP_
#define OSHGUI_APPLICATION_HPP_

#include <memory>
#include "Drawing/IRenderer.hpp"
#include "Misc/DateTime.hpp"
#include "Cursor/Cursor.hpp"
#include "Event/IEvent.hpp"
#include "Event/MouseEvent.hpp"
#include "Exports.hpp"

namespace OSHGui
{
	class Control;
	class Form;
	class Timer;
	class FormManager;
	class TimerManager;

	/**
	 * Stellt static-Methoden und Eigenschaften f�r die Verwaltung einer
	 * Anwendung zur Verf�gung, z.B. Methoden zum Starten und Beenden einer
	 * Anwendung sowie f�r das Abrufen von Informationen zu einer Anwendung.
	 */
	class OSHGUI_EXPORT Application
	{
		friend Form;
		friend Timer;

	public:
		/**
		 * Initialisiert die Application-Klasse.
		 *
		 * @param renderer Instanz des verwendeten Renderers
		 */
		void Create(Drawing::IRenderer *renderer);
		
		/**
		 * Ruft die aktuelle Uhrzeit ab.
		 *
		 * @return DateTime::Now
		 */
		const Misc::DateTime& GetNow() const;
		/**
		 * Ruft den verwendeten Renderer ab.
		 *
		 * @return renderer
		 */
		Drawing::IRenderer* GetRenderer() const;
	
		/**
		 * Aktiviert das GUI.
		 */
		static void Enable();
		/**
		 * Deaktiviert das GUI.
		 */
		static void Disable();
		/**
		 * Wechselt zwischen Enabled und Disabled.
		 */
		static void Toggle();
		/**
		 * Legt die Hauptform des GUI fest.
		 *
		 * @param mainForm die Hauptform, die angezeigt wird, sobald das GUI aktiviert wird
		 */
		static void Run(const std::shared_ptr<Form> &mainForm);
		/**
		 * Gibt ein IEvent an die ge�ffneten Formen weiter.
		 *
		 * @param event
		 * @return NextEventTypes
		 */
		static bool ProcessEvent(IEvent *event);
		static bool ProcessMouseEvent(MouseEvent &mouse);
		/**
		 * Zeichnet die ge�ffneten Formen.
		 */
		static void Render();
		
		static Application* Instance() const;

	private:
		static Application *instance;
	
		static bool isEnabled;
		
		static Drawing::IRenderer *renderer;
	
		static FormManager formManager;
		static TimerManager timerManager;
		
		static Misc::DateTime now;

	public:
		typedef struct
		{
			Drawing::Point Position;
			std::shared_ptr<Cursor> Cursor;
		} MouseInfo;
		static MouseInfo mouse;

		static Control *FocusedControl;
		static Control *ClickedControl;
		static Control *CaptureControl;
		static Control *MouseEnteredControl;
	};
}

#endif