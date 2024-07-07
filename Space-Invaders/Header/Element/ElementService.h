#pragma once

namespace Element
{
	class BunkerController;
	class ElementService
	{
	private:
		BunkerController* bunkerController;

	public:
		ElementService();
		virtual ~ElementService();

		void Initialize();
		void Update();
		void Render();
	};
}