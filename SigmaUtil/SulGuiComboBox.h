// SulGuiComboBox.h

#ifndef __SULGUICOMBOBOX_H__
#define __SULGUICOMBOBOX_H__

#include "SulGuiCanvas.h"
#include "SulGuiTextBox.h"
#include "SulGuiButton.h"
#include "SulGuiListBox.h"
#include "SulSigSlots.h"
#include "SulExport.h"

class SUL_EXPORT CSulGuiComboBox : public CSulGuiCanvas
{
public:
					CSulGuiComboBox( float x, float y, float w, float h );

	virtual void	setupEventHandler( CSulGuiEventHandler* pEventHandler );
	virtual void	setupTheme( CSulGuiThemeXml* pThemeXml );
	virtual void	setupAttr( CSulXmlAttr* pAttr );
	
	virtual void	setLayer( sigma::uint32 layer );

	virtual void	init();

	virtual bool	addChild( Node *child );

	// convience method that creates a CSulGuiText and adds it some a child
	bool			addTextItem( const CSulString& s );

	void			setSelectedIndex( sigma::uint32 index );
	sigma::int32	getSelectedIndex();

	CSulString		getSelectedText();
	CSulGuiItem*	getSelectedItem();

	sigma::signal1<CSulGuiItem*> signalChanged;

	virtual class CSulGuiComboBox*		asComboBox()	{ return this; }

private:
	void			onDropDownClick( CSulGuiCanvas* );
	
	void			onItemChanged( CSulGuiItem* pItem );
	void			onItemClicked( CSulGuiItem* pItem );

private:
	osg::ref_ptr< CSulGuiTextBox >	m_rTextBox;
	osg::ref_ptr< CSulGuiButton >	m_rButton;
	osg::ref_ptr< CSulGuiListBox >	m_rListBox;
};

#endif // __SULGUICOMBOBOX_H__