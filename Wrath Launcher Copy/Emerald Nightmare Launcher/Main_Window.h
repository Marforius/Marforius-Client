#include "stdafx.h"

using namespace std;
#pragma once

inline void LauncherCreateProcess(LPSTR ProcessName)
	{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	int spi=sizeof(pi);
	int ssi= sizeof(si);
	ZeroMemory( &si, sizeof(si) );
	si.cb=sizeof(STARTUPINFO); //sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	int b=0;
	b=CreateProcess( NULL,
		ProcessName,    // Command line.
		NULL,            // Process handle not inheritable.
		NULL,            // Thread handle not inheritable.
		0,          // Set handle inheritance to FALSE.
		ABOVE_NORMAL_PRIORITY_CLASS,               // maximum safe priority for warcraft
		NULL,            // Use parent's environment block.
		NULL,            // Use parent's starting directory.
		&si,              // Pointer to STARTUPINFO structure.
		&pi );
	delete ProcessName;
	exit(0);
	}

inline bool LauncherDeleteFile(LPCTSTR lpszDir, bool noRecycleBin = true)
	{
	int len = _tcslen(lpszDir);
	TCHAR *pszFrom = new TCHAR[len+2];
	_tcscpy(pszFrom, lpszDir);
	pszFrom[len] = 0;
	pszFrom[len+1] = 0;

	SHFILEOPSTRUCT fileop;
	fileop.hwnd   = NULL;    // no status display
	fileop.wFunc  = FO_DELETE;  // delete operation
	fileop.pFrom  = pszFrom;  // source file name as double null terminated string
	fileop.pTo    = NULL;    // no destination needed
	fileop.fFlags = FOF_NOCONFIRMATION|FOF_SILENT;  // do not prompt the user

	if(!noRecycleBin)
		fileop.fFlags |= FOF_ALLOWUNDO;

	fileop.fAnyOperationsAborted = FALSE;
	fileop.lpszProgressTitle     = NULL;
	fileop.hNameMappings         = NULL;

	int ret = SHFileOperation(&fileop);
	delete [] pszFrom;
	delete lpszDir;
	return (ret == 0);
	}

namespace EmeraldNightmareLauncher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Main_Window
	/// </summary>
	public ref class Main_Window : public System::Windows::Forms::Form
		{
		public:
			Main_Window(void)
				{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
				}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Main_Window()
				{
				if (components)
					{
					delete components;
					}
				}
		private: System::Windows::Forms::WebBrowser^  webBrowser1;
		private: System::Windows::Forms::Button^  button1;

		private: System::Windows::Forms::MenuStrip^  menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^  test1ToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  forceLauncherUpdateToolStripMenuItem;


		private: System::Windows::Forms::ToolStripMenuItem^  cleanupToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  consolidatePatchesToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  deleteSettingsToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  deleteNonessentialFilesToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  clientSystemChecksToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  mD5CheckArchivesToolStripMenuItem1;
		private: System::Windows::Forms::ToolStripMenuItem^  deleteWarcraftsCacheToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  addOnsToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  downloadReccomendedAddonsToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  shareGathererDataAcrossAllAccountsToolStripMenuItem;

		private: System::Windows::Forms::ToolStripMenuItem^  marforiusClientToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  downloadMarforiusClientToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  editSavedServersToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  clientSystemCheckToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  developerToolStripMenuItem;

		private: System::Windows::Forms::ToolStripMenuItem^  gMToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  toggleDebugToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  downloadAddOnToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  deleteARCHIVEFrameGlueAddOnsToolStripMenuItem;
		private: System::Windows::Forms::LinkLabel^  LauncherAlertBox;
		private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;





		protected: 

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
				{
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_Window::typeid));
				this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->test1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->forceLauncherUpdateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->cleanupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->consolidatePatchesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->deleteSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->deleteNonessentialFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->deleteWarcraftsCacheToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->clientSystemChecksToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->mD5CheckArchivesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->addOnsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->downloadReccomendedAddonsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->marforiusClientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->downloadMarforiusClientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->editSavedServersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->clientSystemCheckToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->developerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toggleDebugToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->gMToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->downloadAddOnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->LauncherAlertBox = (gcnew System::Windows::Forms::LinkLabel());
				this->menuStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// webBrowser1
				// 
				this->webBrowser1->AllowWebBrowserDrop = false;
				this->webBrowser1->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->webBrowser1->Location = System::Drawing::Point(0, 24);
				this->webBrowser1->Margin = System::Windows::Forms::Padding(0);
				this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
				this->webBrowser1->Name = L"webBrowser1";
				this->webBrowser1->ScriptErrorsSuppressed = true;
				this->webBrowser1->ScrollBarsEnabled = false;
				this->webBrowser1->Size = System::Drawing::Size(636, 402);
				this->webBrowser1->TabIndex = 0;
				this->webBrowser1->Url = (gcnew System::Uri(L"http://www.assembla.com/code/emerald-nightmare-launcher/subversion/node/blob/inde" 
					L"x.html", 
					System::UriKind::Absolute));
				this->webBrowser1->DocumentCompleted += gcnew System::Windows::Forms::WebBrowserDocumentCompletedEventHandler(this, &Main_Window::webBrowser1_DocumentCompleted);
				// 
				// button1
				// 
				this->button1->AutoSize = true;
				this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
				this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
				this->button1->Location = System::Drawing::Point(486, 428);
				this->button1->Margin = System::Windows::Forms::Padding(0);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(147, 90);
				this->button1->TabIndex = 1;
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &Main_Window::button1_Click);
				// 
				// menuStrip1
				// 
				this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(44)), 
					static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->test1ToolStripMenuItem, 
					this->cleanupToolStripMenuItem, this->clientSystemChecksToolStripMenuItem, this->addOnsToolStripMenuItem, this->marforiusClientToolStripMenuItem, 
					this->developerToolStripMenuItem, this->gMToolStripMenuItem, this->aboutToolStripMenuItem});
				this->menuStrip1->Location = System::Drawing::Point(0, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
				this->menuStrip1->Size = System::Drawing::Size(636, 24);
				this->menuStrip1->TabIndex = 3;
				this->menuStrip1->Text = L"menuStrip1";
				this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Main_Window::menuStrip1_ItemClicked);
				// 
				// test1ToolStripMenuItem
				// 
				this->test1ToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->test1ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->forceLauncherUpdateToolStripMenuItem});
				this->test1ToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->test1ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->test1ToolStripMenuItem->Name = L"test1ToolStripMenuItem";
				this->test1ToolStripMenuItem->Size = System::Drawing::Size(59, 20);
				this->test1ToolStripMenuItem->Text = L"General";
				this->test1ToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				this->test1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::test1ToolStripMenuItem_Click);
				// 
				// forceLauncherUpdateToolStripMenuItem
				// 
				this->forceLauncherUpdateToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->forceLauncherUpdateToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->forceLauncherUpdateToolStripMenuItem->Name = L"forceLauncherUpdateToolStripMenuItem";
				this->forceLauncherUpdateToolStripMenuItem->Size = System::Drawing::Size(196, 22);
				this->forceLauncherUpdateToolStripMenuItem->Text = L"Force Launcher Update";
				this->forceLauncherUpdateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::forceLauncherUpdateToolStripMenuItem_Click);
				// 
				// cleanupToolStripMenuItem
				// 
				this->cleanupToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->cleanupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->consolidatePatchesToolStripMenuItem, 
					this->deleteSettingsToolStripMenuItem, this->deleteNonessentialFilesToolStripMenuItem, this->deleteWarcraftsCacheToolStripMenuItem});
				this->cleanupToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->cleanupToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->cleanupToolStripMenuItem->Name = L"cleanupToolStripMenuItem";
				this->cleanupToolStripMenuItem->Size = System::Drawing::Size(63, 20);
				this->cleanupToolStripMenuItem->Text = L"Cleanup";
				this->cleanupToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				// 
				// consolidatePatchesToolStripMenuItem
				// 
				this->consolidatePatchesToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->consolidatePatchesToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->consolidatePatchesToolStripMenuItem->Name = L"consolidatePatchesToolStripMenuItem";
				this->consolidatePatchesToolStripMenuItem->Size = System::Drawing::Size(209, 22);
				this->consolidatePatchesToolStripMenuItem->Text = L"Consolidate Patches";
				this->consolidatePatchesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::consolidatePatchesToolStripMenuItem_Click);
				// 
				// deleteSettingsToolStripMenuItem
				// 
				this->deleteSettingsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->deleteSettingsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->deleteSettingsToolStripMenuItem->Name = L"deleteSettingsToolStripMenuItem";
				this->deleteSettingsToolStripMenuItem->Size = System::Drawing::Size(209, 22);
				this->deleteSettingsToolStripMenuItem->Text = L"Delete Settings";
				this->deleteSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::deleteSettingsToolStripMenuItem_Click);
				// 
				// deleteNonessentialFilesToolStripMenuItem
				// 
				this->deleteNonessentialFilesToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->deleteNonessentialFilesToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->deleteNonessentialFilesToolStripMenuItem->Name = L"deleteNonessentialFilesToolStripMenuItem";
				this->deleteNonessentialFilesToolStripMenuItem->Size = System::Drawing::Size(209, 22);
				this->deleteNonessentialFilesToolStripMenuItem->Text = L"Delete Non-Essential Files";
				this->deleteNonessentialFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::deleteNonessentialFilesToolStripMenuItem_Click);
				// 
				// deleteWarcraftsCacheToolStripMenuItem
				// 
				this->deleteWarcraftsCacheToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->deleteWarcraftsCacheToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->deleteWarcraftsCacheToolStripMenuItem->Name = L"deleteWarcraftsCacheToolStripMenuItem";
				this->deleteWarcraftsCacheToolStripMenuItem->Size = System::Drawing::Size(209, 22);
				this->deleteWarcraftsCacheToolStripMenuItem->Text = L"Delete Warcraft\'s Cache";
				this->deleteWarcraftsCacheToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::deleteWarcraftsCacheToolStripMenuItem_Click_1);
				// 
				// clientSystemChecksToolStripMenuItem
				// 
				this->clientSystemChecksToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->clientSystemChecksToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mD5CheckArchivesToolStripMenuItem1});
				this->clientSystemChecksToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->clientSystemChecksToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->clientSystemChecksToolStripMenuItem->Name = L"clientSystemChecksToolStripMenuItem";
				this->clientSystemChecksToolStripMenuItem->Size = System::Drawing::Size(129, 20);
				this->clientSystemChecksToolStripMenuItem->Text = L"ClientSystem Checks";
				this->clientSystemChecksToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				this->clientSystemChecksToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::clientSystemChecksToolStripMenuItem_Click);
				// 
				// mD5CheckArchivesToolStripMenuItem1
				// 
				this->mD5CheckArchivesToolStripMenuItem1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->mD5CheckArchivesToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
				this->mD5CheckArchivesToolStripMenuItem1->Name = L"mD5CheckArchivesToolStripMenuItem1";
				this->mD5CheckArchivesToolStripMenuItem1->Size = System::Drawing::Size(181, 22);
				this->mD5CheckArchivesToolStripMenuItem1->Text = L"MD5 Check archives";
				this->mD5CheckArchivesToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Main_Window::mD5CheckArchivesToolStripMenuItem1_Click);
				// 
				// addOnsToolStripMenuItem
				// 
				this->addOnsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->addOnsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->downloadReccomendedAddonsToolStripMenuItem, 
					this->shareGathererDataAcrossAllAccountsToolStripMenuItem});
				this->addOnsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->addOnsToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->addOnsToolStripMenuItem->Name = L"addOnsToolStripMenuItem";
				this->addOnsToolStripMenuItem->Size = System::Drawing::Size(62, 20);
				this->addOnsToolStripMenuItem->Text = L"AddOns";
				this->addOnsToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				// 
				// downloadReccomendedAddonsToolStripMenuItem
				// 
				this->downloadReccomendedAddonsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->downloadReccomendedAddonsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->downloadReccomendedAddonsToolStripMenuItem->Name = L"downloadReccomendedAddonsToolStripMenuItem";
				this->downloadReccomendedAddonsToolStripMenuItem->Size = System::Drawing::Size(286, 22);
				this->downloadReccomendedAddonsToolStripMenuItem->Text = L"Download Recommended Addons";
				this->downloadReccomendedAddonsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::downloadReccomendedAddonsToolStripMenuItem_Click);
				// 
				// shareGathererDataAcrossAllAccountsToolStripMenuItem
				// 
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem->Name = L"shareGathererDataAcrossAllAccountsToolStripMenuItem";
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem->Size = System::Drawing::Size(286, 22);
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem->Text = L"Share Gatherer Data Across All Accounts";
				this->shareGathererDataAcrossAllAccountsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::shareGathererDataAcrossAllAccountsToolStripMenuItem_Click);
				// 
				// marforiusClientToolStripMenuItem
				// 
				this->marforiusClientToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->marforiusClientToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->downloadMarforiusClientToolStripMenuItem, 
					this->editSavedServersToolStripMenuItem, this->clientSystemCheckToolStripMenuItem, this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem});
				this->marforiusClientToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->marforiusClientToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->marforiusClientToolStripMenuItem->Name = L"marforiusClientToolStripMenuItem";
				this->marforiusClientToolStripMenuItem->Size = System::Drawing::Size(106, 20);
				this->marforiusClientToolStripMenuItem->Text = L"Marforius-Client";
				this->marforiusClientToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				// 
				// downloadMarforiusClientToolStripMenuItem
				// 
				this->downloadMarforiusClientToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->downloadMarforiusClientToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->downloadMarforiusClientToolStripMenuItem->Name = L"downloadMarforiusClientToolStripMenuItem";
				this->downloadMarforiusClientToolStripMenuItem->Size = System::Drawing::Size(271, 22);
				this->downloadMarforiusClientToolStripMenuItem->Text = L"Download Marforius-Client";
				this->downloadMarforiusClientToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::downloadMarforiusClientToolStripMenuItem_Click);
				// 
				// editSavedServersToolStripMenuItem
				// 
				this->editSavedServersToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->editSavedServersToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->editSavedServersToolStripMenuItem->Name = L"editSavedServersToolStripMenuItem";
				this->editSavedServersToolStripMenuItem->Size = System::Drawing::Size(271, 22);
				this->editSavedServersToolStripMenuItem->Text = L"Edit Saved Servers";
				this->editSavedServersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::editSavedServersToolStripMenuItem_Click);
				// 
				// clientSystemCheckToolStripMenuItem
				// 
				this->clientSystemCheckToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->clientSystemCheckToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->clientSystemCheckToolStripMenuItem->Name = L"clientSystemCheckToolStripMenuItem";
				this->clientSystemCheckToolStripMenuItem->Size = System::Drawing::Size(271, 22);
				this->clientSystemCheckToolStripMenuItem->Text = L"ClientSystem Check";
				this->clientSystemCheckToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::clientSystemCheckToolStripMenuItem_Click);
				// 
				// deleteARCHIVEFrameGlueAddOnsToolStripMenuItem
				// 
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem->Name = L"deleteARCHIVEFrameGlueAddOnsToolStripMenuItem";
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem->Size = System::Drawing::Size(271, 22);
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem->Text = L"Delete ARCHIVE Frame/Glue/AddOns";
				this->deleteARCHIVEFrameGlueAddOnsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::deleteARCHIVEFrameGlueAddOnsToolStripMenuItem_Click);
				// 
				// developerToolStripMenuItem
				// 
				this->developerToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->developerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toggleDebugToolStripMenuItem});
				this->developerToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->developerToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->developerToolStripMenuItem->Name = L"developerToolStripMenuItem";
				this->developerToolStripMenuItem->Size = System::Drawing::Size(72, 20);
				this->developerToolStripMenuItem->Text = L"Developer";
				this->developerToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				// 
				// toggleDebugToolStripMenuItem
				// 
				this->toggleDebugToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->toggleDebugToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->toggleDebugToolStripMenuItem->Name = L"toggleDebugToolStripMenuItem";
				this->toggleDebugToolStripMenuItem->Size = System::Drawing::Size(149, 22);
				this->toggleDebugToolStripMenuItem->Text = L"Toggle Debug";
				this->toggleDebugToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::toggleDebugToolStripMenuItem_Click);
				// 
				// gMToolStripMenuItem
				// 
				this->gMToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), 
					static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
				this->gMToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->downloadAddOnToolStripMenuItem});
				this->gMToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->gMToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->gMToolStripMenuItem->Name = L"gMToolStripMenuItem";
				this->gMToolStripMenuItem->Size = System::Drawing::Size(38, 20);
				this->gMToolStripMenuItem->Text = L"GM";
				this->gMToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
				// 
				// downloadAddOnToolStripMenuItem
				// 
				this->downloadAddOnToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
				this->downloadAddOnToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->downloadAddOnToolStripMenuItem->Name = L"downloadAddOnToolStripMenuItem";
				this->downloadAddOnToolStripMenuItem->Size = System::Drawing::Size(169, 22);
				this->downloadAddOnToolStripMenuItem->Text = L"Download AddOn";
				this->downloadAddOnToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::downloadAddOnToolStripMenuItem_Click);
				// 
				// aboutToolStripMenuItem
				// 
				this->aboutToolStripMenuItem->ForeColor = System::Drawing::Color::White;
				this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
				this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
				this->aboutToolStripMenuItem->Text = L"About";
				this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::aboutToolStripMenuItem_Click);
				// 
				// LauncherAlertBox
				// 
				this->LauncherAlertBox->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
					static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->LauncherAlertBox->BackColor = System::Drawing::Color::Transparent;
				this->LauncherAlertBox->CausesValidation = false;
				this->LauncherAlertBox->DisabledLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
					static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->LauncherAlertBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(0)));
				this->LauncherAlertBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->LauncherAlertBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"LauncherAlertBox.Image")));
				this->LauncherAlertBox->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->LauncherAlertBox->Location = System::Drawing::Point(-3, 426);
				this->LauncherAlertBox->Name = L"LauncherAlertBox";
				this->LauncherAlertBox->Size = System::Drawing::Size(486, 92);
				this->LauncherAlertBox->TabIndex = 4;
				// 
				// Main_Window
				// 
				this->AcceptButton = this->button1;
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->AutoSize = true;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)), 
					static_cast<System::Int32>(static_cast<System::Byte>(20)));
				this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
				this->ClientSize = System::Drawing::Size(636, 517);
				this->Controls->Add(this->menuStrip1);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->webBrowser1);
				this->Controls->Add(this->LauncherAlertBox);
				this->DoubleBuffered = true;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
				this->MainMenuStrip = this->menuStrip1;
				this->MaximizeBox = false;
				this->Name = L"Main_Window";
				this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Emerald Nightmare Launcher";
				this->Load += gcnew System::EventHandler(this, &Main_Window::Main_Window_Load);
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

				}
#pragma endregion
		private: System::Void webBrowser1_DocumentCompleted(System::Object^  sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^  e) {

					 // The following is a model of the update process:
					 // Download LauncherVersion.ini
					 // Open and store value in string
					 // Compare VersionAtCompile and VersionOfRemoteIni
					 // if remote greater then version at compile, then call autoupdater.exe -RunMain :: Autoupdater will delete this file, and update it with whatever is in the remote /updates/ directory
					 // fin, really simple versioning/update system

					 URLDownloadToFile ( NULL, _T("http://www.assembla.com/code/emerald-nightmare-launcher/subversion/node/blob/updates/LauncherVersion.ini"), _T("LauncherVersion.ini"), 0, NULL );

					 int VersionAtCompile=2; // remember to set this

					 string VerofRemoteBeforeConvert;
					 ifstream infile;
					 infile.open ("LauncherVersion.ini");
					 getline(infile,VerofRemoteBeforeConvert); // Saves the line in STRING.
					 infile.close();

					 int VersionOfRemoteIni = atoi( VerofRemoteBeforeConvert.c_str() ); // convert...

					 if(VersionOfRemoteIni > VersionAtCompile)
						 {
						 URLDownloadToFile ( NULL, _T("http://www.assembla.com/code/emerald-nightmare-launcher/subversion/node/blob/updates/AutoUpdater.exe"), _T("AutoUpdater.exe"), 0, NULL );
						 LauncherAlertBox->Text = "";
						 LauncherAlertBox->Text = "An updated version is available, one moment while the launcher is updated.";
						 Sleep(5000);
						 VerofRemoteBeforeConvert.clear();
						 VersionAtCompile = 0;
						 VersionOfRemoteIni = 0;
						 LauncherCreateProcess("AutoUpdater.exe -RunMain");
						 }
					 VerofRemoteBeforeConvert.clear();
					 VersionAtCompile = 0;
					 VersionOfRemoteIni = 0;
					 }
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("wow.exe -console");
					 }
		private: System::Void test1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 }
		private: System::Void forceLauncherUpdateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

					 URLDownloadToFile ( NULL, _T("http://www.assembla.com/code/emerald-nightmare-launcher/subversion/node/blob/updates/AutoUpdater.exe"), _T("AutoUpdater.exe"), 0, NULL );
					 Sleep(5000);
					 LauncherCreateProcess("AutoUpdater.exe -RunMain");
					 }
		private: System::Void mD5CheckArchivesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 //                         Vanilla (3.3.5A) MD5 Hashes
					 //				 \\data\\
					 //					 17d340dbd0ac02569d56cd0d96b2c8b7 *common-2.MPQ
					 //					 325452ce19054ee76f29acb14da85884 *common.MPQ
					 //					 c48af167bd3253f4762dd077112252af *expansion.MPQ
					 //					 6c9f85caf621ee546dbfe8811315eb11 *lichking.MPQ
					 //					 ab3a08a2993caec2db8c2c181f5f5065 *patch-2.MPQ
					 //					 35733b76fcf0f95a0d8240d1f36cc5c3 *patch-3.MPQ
					 //					 88e4545c0074f9d6c1eced7e035bdf6e *patch-4.MPQ
					 //					 6e099a82d9d2bb75c037625aecaa34aa *patch.MPQ
					 //					 \\data\\enUS\\
					 //					 2aa2c2c6aa341977ec15ee75d13a2429 *backup-enUS.MPQ
					 //					 0423b93701903133e282247b74822364 *base-enUS.MPQ
					 //					 c9b1786849ade7f399c57da8c61fe352 *expansion-locale-enUS.MPQ
					 //					 4077b16db9fe39f81fadbb2098ece280 *expansion-speech-enUS.MPQ
					 //					 af01bc97ca87104c589d4d84684d3b4e *lichking-locale-enUS.MPQ
					 //					 be2a6737bb323b700c3d750ca9b72709 *lichking-speech-enUS.MPQ
					 //					 6a2d75fad8d317b0bedaa4f82f9340a5 *locale-enUS.MPQ
					 //					 2352dfdbb85174d80b748a1111c56ee9 *patch-enUS-2.MPQ
					 //					 5514621925fa8cd17e864fabcbf85b4a *patch-enUS-3.MPQ
					 //					 273cc8a0137dbc6f978c74acaa809098 *patch-enUS.MPQ
					 //					 965021d466779f68407965f4759c5cc6 *speech-enUS.MPQ
					 //					 
					 //					       Packed or Repacked (3.3.5A) MD5 Hashes
					 //					             (Using custom repacker tool, without textfile generation for signature, will not match current Repacker.exe output)
					 //                              (HASHTABLES WERE SET TO MAXIMUM FOR THESE MD5s)
					 //					              \\data\\
					 //					              d7ae8eab68248604d640548f1a3b6527 *common.MPQ
					 //					              5643de2e29ffedcadff3eb6b3febfe77 *common-2.MPQ
					 //					              2b5f10292180ae8d9a378ab2051daa47 *expansion.MPQ
					 //					              a270a7133f743ed6a0278b73463d3657 *lichking.MPQ
					 //					              b63f05db29a2e659d92451f32934c6be *patch.MPQ
					 //					              \\data\\enUS\\
					 //					              7c9742cef1f777f9a92a0f911cf92a11 *expansion-locale-enUS.MPQ
					 //					              aa506008faed178f2fa0abb9bcb86ccd *expansion-speech-enUS.MPQ
					 //					              2d92f4a4f75347f9778e2b73a85087e4 *lichking-locale-enUS.MPQ
					 //					              e7ec7cc3cad40a77fc2451872d381bdd *lichking-speech-enUS.MPQ
					 //					              ba03e06f36572240e4e7e8185ff6a2cc *locale-enUS.MPQ
					 //					              f6065bd0d0340edbd702023cc0d7f5f6 *patch-enUS.MPQ
					 //					              443b1b20d16a0972e8c435e8d0bf45ea *speech-enUS.MPQ
					 //					              
					 // TODO: Logic
					 // MD5 generate per file
					 // If match retail then ok
					 // if match marforius-client then give message about test working fine
					 // if match launcherrepacked then ok
					 // if else, CORRUPTED
					 // if corrupted offer to open torrent webpage to download new data files
					 // fin
					 // 
					 LauncherCreateProcess("StormProxy.exe -RunCHECKARCHIVES");
					 }
		private: System::Void deleteNonessentialFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

					 // main directory
					 LauncherDeleteFile("Cache", false);
					 LauncherDeleteFile("Logger.exe", false);
					 LauncherDeleteFile("Util.dll", false);
					 LauncherDeleteFile("Battle.net.dll", false);
					 LauncherDeleteFile("Changelog.URL", false);
					 LauncherDeleteFile("Create Account.URL", false);
					 //"DivxDecoder.dll", false); // see below why this is commented
					 LauncherDeleteFile("Features.URL", false);
					 LauncherDeleteFile("Molten Official Website.URL", false);
					 LauncherDeleteFile("Repair.exe", false);
					 LauncherDeleteFile("dbghelp.dll", false);
					 LauncherDeleteFile("ijl15.dll", false);
					 LauncherDeleteFile("msvcr80.dll", false);
					 LauncherDeleteFile("unicows.dll", false);

					 // interface\\addons directory
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_AchievementUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_ArenaUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_AuctionUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_BarbershopUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_BattlefieldMinimap", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_BindingUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_Calendar", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_CombatLog", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_CombatText", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_DebugTools", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_GMChatUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_GMSurveyUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_GlyphUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_GuildBankUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_InspectUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_ItemSocketingUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_MacroUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_RaidUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_TalentUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_TimeManager", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_TokenUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_TradeSkillUI", false);
					 LauncherDeleteFile("Interface\\AddOns\\Blizzard_TrainerUI", false);

					 // under data\\enUS directory
					 LauncherDeleteFile("Data\\enUS\\Documentation", false);

					 //"Data\\enUS\\Interface", false);

					 // movies, divx codec - this functionality still exists in Marforius-Client however the client will crash if movies are played WITHOUT
					 // divx codec in directory, Marforius-Client just is smart enough to launch without the divx codec needed being there,
					 // official client however will not load without the dll

					 LauncherDeleteFile("Data\\enUS\\AccountBilling.url", false);
					 LauncherDeleteFile("Data\\enUS\\Credits.html", false);
					 LauncherDeleteFile("Data\\enUS\\Credits_BC.html", false);
					 LauncherDeleteFile("Data\\enUS\\Credits_LK.html", false);
					 LauncherDeleteFile("Data\\enUS\\TechSupport.url", false);
					 LauncherDeleteFile("Data\\enUS\\connection-help.html", false);
					 LauncherDeleteFile("Data\\enUS\\eula.html", false);
					 LauncherDeleteFile("Data\\enUS\\realmlist.wtf", false);
					 LauncherDeleteFile("Data\\enUS\\tos.html", false);

					 // don't think I missed anything as per http://torrentz.eu/35414f8be8348a08a49fc4ccfb29093e22f1d628


					 // more junk
					 LauncherDeleteFile("Patch", false);
					 LauncherDeleteFile("Patches", false);
					 LauncherDeleteFile("Old", false);
					 LauncherDeleteFile("Logs", false);
					 LauncherDeleteFile("Errors", false);
					 LauncherDeleteFile("pgort100.dll", false);
					 LauncherDeleteFile("Logger.exe", false);
					 LauncherDeleteFile("Util.dll", false);
					 LauncherDeleteFile(".curseclient", false);
					 LauncherDeleteFile("LauncherVersion.ini", false);
					 LauncherDeleteFile("DeveloperStreamingControl.ini", false);
					 LauncherDeleteFile("wow.ini", false);
					 LauncherDeleteFile("Data\\allfiles.md5", false);
					 LauncherDeleteFile("Data\\enUS\\allfiles.md5", false);

					 // should really rig something up to grab dev archive
					 LauncherDeleteFile("streamingloc.MPQ", false);
					 LauncherDeleteFile("streaming.MPQ", false);
					 LauncherDeleteFile("development.MPQ", false);
					 LauncherDeleteFile("lichkingloc.MPQ", false);
					 LauncherDeleteFile("expansionloc.MPQ", false);
					 LauncherDeleteFile("dbc.MPQ", false);
					 LauncherDeleteFile("fonts.MPQ", false);
					 LauncherDeleteFile("sound.MPQ", false);
					 LauncherDeleteFile("wmo.MPQ", false);
					 LauncherDeleteFile("terrain.MPQ", false);
					 LauncherDeleteFile("texture.MPQ", false);
					 LauncherDeleteFile("model.MPQ", false);
					 LauncherDeleteFile("misc.MPQ", false);
					 LauncherDeleteFile("interface.MPQ", false);
					 LauncherDeleteFile("alternate.MPQ", false);
					 LauncherDeleteFile("Start.MPQ", false);
					 LauncherDeleteFile("Installer Tome.MPQ", false);
					 LauncherDeleteFile("Movies.MPQ", false);
					 LauncherDeleteFile("agreements.mpq", false);
					 LauncherDeleteFile("wow-patch.mpq", false);
					 LauncherDeleteFile("Data\\base.MPQ", false);

					 LauncherDeleteFile("Data\\streamingloc.MPQ", false);
					 LauncherDeleteFile("Data\\streaming.MPQ", false);
					 LauncherDeleteFile("Data\\development.MPQ", false);
					 LauncherDeleteFile("Data\\lichkingloc.MPQ", false);
					 LauncherDeleteFile("Data\\expansionloc.MPQ", false);
					 LauncherDeleteFile("Data\\dbc.MPQ", false);
					 LauncherDeleteFile("Data\\fonts.MPQ", false);
					 LauncherDeleteFile("Data\\sound.MPQ", false);
					 LauncherDeleteFile("Data\\wmo.MPQ", false);
					 LauncherDeleteFile("Data\\terrain.MPQ", false);
					 LauncherDeleteFile("Data\\texture.MPQ", false);
					 LauncherDeleteFile("Data\\model.MPQ", false);
					 LauncherDeleteFile("Data\\misc.MPQ", false);
					 LauncherDeleteFile("Data\\interface.MPQ", false);
					 LauncherDeleteFile("Data\\alternate.MPQ", false);
					 LauncherDeleteFile("Data\\Start.MPQ", false);
					 LauncherDeleteFile("Data\\Installer Tome.MPQ", false);
					 LauncherDeleteFile("Data\\Movies.MPQ", false);
					 LauncherDeleteFile("Data\\agreements.mpq", false);
					 LauncherDeleteFile("Data\\wow-patch.mpq", false);
					 LauncherDeleteFile("Data\\base.MPQ", false);
					 LauncherDeleteFile("Data\\realmlist.wtf", false);
					 LauncherDeleteFile("Data\\enUS\\realmlist.wtf", false);

					 LauncherAlertBox->Text = "";
					 LauncherAlertBox->Text = "Deleting Non-Essential files that won't be used in a private server environment(bloat)... \r\n\r\nYou should now relaunch World of Warcraft and close it to generate temporary files it needs. Realmlist.wtf is now integrated into WTF\\Config.wtf";
					 }
		private: System::Void deleteWarcraftsCacheToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
					 LauncherDeleteFile("Cache", false);
					 LauncherAlertBox->Text = "";
					 LauncherAlertBox->Text = "Deleted Cache...";
					 }
		private: System::Void shareGathererDataByLastEditedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 // DO NOT IMPLEMENT
					 }
		private: System::Void downloadReccomendedAddonsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("AutoUpdater.exe -DownloadAddons");
					 }
		private: System::Void shareGathererDataAcrossAllAccountsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 // TODO: copy the biggest gatherer saved data file across all account folders
					 }
		private: System::Void downloadMarforiusClientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("AutoUpdater.exe -DownloadMarforiusClient");
					 }
		private: System::Void editSavedServersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 }
		private: System::Void clientSystemCheckToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("StormProxy.exe -RunCHECKARCHIVES");
					 }
		private: System::Void mD5CheckArchivesToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("StormProxy.exe -RunCHECKARCHIVES");
					 }
		private: System::Void consolidatePatchesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("StormProxy.exe -RunREPACKPATCHESINTOPARENTMPQ");
					 }
		private: System::Void deleteSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherDeleteFile("WTF", false);
					 LauncherDeleteFile("Cache", false);
					 LauncherAlertBox->Text = "";
					 LauncherAlertBox->Text = "Deleted Cache and Settings...";
					 }
		private: System::Void clientSystemChecksToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("StormProxy.exe -RunCHECKARCHIVES");
					 }
		private: System::Void deleteARCHIVEFrameGlueAddOnsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("StormProxy.exe -RunDELETEARCHIVEINTERFACEFILES");
					 }
		private: System::Void toggleDebugToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 }
		private: System::Void downloadAddOnToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherCreateProcess("AutoUpdater.exe -DownloadNightmareAdmin");
					 }
		private: System::Void richlinkLabel1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
					 }
		private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
					 }
		private: System::Void Main_Window_Load(System::Object^  sender, System::EventArgs^  e) {
					 }
		private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 LauncherAlertBox->Text = "";
					 LauncherAlertBox->Text = "";
					 }
		};
	}



// TODO: edit the contents of Marforius-Client's options file
// TODO: Delete realmlist.wtf on launch and SET Emerald Nightmare's realmlist AS DEFAULT
// 