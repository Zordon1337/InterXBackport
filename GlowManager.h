#pragma once 

class CGlowObjectManager
{
public:
	class GlowObjectDefinition_t
	{
	public:
		void set(Color color)
		{
			m_vGlowColor = Vector(color.rBase(), color.gBase(), color.bBase());
			m_flGlowAlpha = color.aBase();
			m_bRenderWhenOccluded = true;
			m_bRenderWhenUnoccluded = false;
		}

		IClientEntity* getEntity()
		{
			return m_hEntity;
		}

		bool IsEmpty() const { return m_nNextFreeSlot != GlowObjectDefinition_t::ENTRY_IN_USE; }

	public:
		IClientEntity* m_hEntity;
		Vector m_vGlowColor;
		float m_flGlowAlpha;

		bool m_bRenderWhenOccluded;
		bool m_bRenderWhenUnoccluded;
		int m_nSplitScreenSlot;

		// Linked list of free slots
		int m_nNextFreeSlot;

		// Special values for GlowObjectDefinition_t::m_nNextFreeSlot
		static const int END_OF_FREE_LIST = -1;
		static const int ENTRY_IN_USE = -2;
	};

	GlowObjectDefinition_t* m_GlowObjectDefinitions;
	int		max_size;
	int		pad;
	int		size;
};