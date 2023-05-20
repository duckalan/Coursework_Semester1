#pragma once
#include "HealthEntry.h"
#include "EntryTableUserControl.h"
#include "FilterFunctions.h"
#include "PressurePlotForm.h"
#include "PressureRatioForm.h"

namespace Sketch 
{

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Linq;
	using namespace Utility;

	public ref class MainForm : public System::Windows::Forms::Form
	{
		/// <summary>
		/// Счётчик новых вкладок для добавления нумерации в их названия.
		/// Используется при создании новых файлов как стандартное имя.
		/// </summary>
		int _newTabPageCounter = 1;

	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ mainTabControl;
	private: System::Windows::Forms::TabPage^ initialTabPage;
	private: System::Windows::Forms::MenuStrip^ mainMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ newFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ filtersToolStripMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ pressureFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ healthStateFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pulseFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ additionalToolStripMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ morningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eveningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ goodToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ satisfactoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ higher120ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ oneMonthPressurePlotToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pressureRatioToolStripMenuItem;
	private: System::Windows::Forms::Panel^ initialPanel;
	private: System::Windows::Forms::Button^ createNewFileButton;
	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Label^ welcomeLabel;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ nightToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ unsatisfactoryToolStripMenuItem;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->initialTabPage = (gcnew System::Windows::Forms::TabPage());
			this->initialPanel = (gcnew System::Windows::Forms::Panel());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->createNewFileButton = (gcnew System::Windows::Forms::Button());
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->mainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtersToolStripMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pressureFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->morningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eveningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->healthStateFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->goodToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->satisfactoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unsatisfactoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pulseFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->higher120ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->additionalToolStripMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oneMonthPressurePlotToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pressureRatioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->mainTabControl->SuspendLayout();
			this->initialTabPage->SuspendLayout();
			this->initialPanel->SuspendLayout();
			this->mainMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTabControl
			// 
			this->mainTabControl->Controls->Add(this->initialTabPage);
			this->mainTabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainTabControl->HotTrack = true;
			this->mainTabControl->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->mainTabControl->Location = System::Drawing::Point(0, 27);
			this->mainTabControl->Name = L"mainTabControl";
			this->mainTabControl->SelectedIndex = 0;
			this->mainTabControl->Size = System::Drawing::Size(884, 334);
			this->mainTabControl->TabIndex = 0;
			this->mainTabControl->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &MainForm::mainTabControl_Selected);
			// 
			// initialTabPage
			// 
			this->initialTabPage->Controls->Add(this->initialPanel);
			this->initialTabPage->Location = System::Drawing::Point(4, 25);
			this->initialTabPage->Name = L"initialTabPage";
			this->initialTabPage->Padding = System::Windows::Forms::Padding(3);
			this->initialTabPage->Size = System::Drawing::Size(876, 305);
			this->initialTabPage->TabIndex = 0;
			this->initialTabPage->Text = L"Начальное окно";
			this->initialTabPage->UseVisualStyleBackColor = true;
			// 
			// initialPanel
			// 
			this->initialPanel->Controls->Add(this->welcomeLabel);
			this->initialPanel->Controls->Add(this->createNewFileButton);
			this->initialPanel->Controls->Add(this->openFileButton);
			this->initialPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->initialPanel->Location = System::Drawing::Point(3, 3);
			this->initialPanel->Name = L"initialPanel";
			this->initialPanel->Size = System::Drawing::Size(870, 299);
			this->initialPanel->TabIndex = 2;
			// 
			// welcomeLabel
			// 
			this->welcomeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->welcomeLabel->AutoSize = true;
			this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->welcomeLabel->Location = System::Drawing::Point(335, 50);
			this->welcomeLabel->Name = L"welcomeLabel";
			this->welcomeLabel->Size = System::Drawing::Size(231, 29);
			this->welcomeLabel->TabIndex = 2;
			this->welcomeLabel->Text = L"Добро пожаловать";
			// 
			// createNewFileButton
			// 
			this->createNewFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->createNewFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->createNewFileButton->Location = System::Drawing::Point(230, 120);
			this->createNewFileButton->MaximumSize = System::Drawing::Size(300, 100);
			this->createNewFileButton->MinimumSize = System::Drawing::Size(150, 50);
			this->createNewFileButton->Name = L"createNewFileButton";
			this->createNewFileButton->Size = System::Drawing::Size(150, 50);
			this->createNewFileButton->TabIndex = 0;
			this->createNewFileButton->Text = L"Создать файл";
			this->createNewFileButton->UseVisualStyleBackColor = true;
			this->createNewFileButton->Click += gcnew System::EventHandler(this, &MainForm::createNewFileButton_Click);
			// 
			// openFileButton
			// 
			this->openFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->openFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openFileButton->Location = System::Drawing::Point(485, 120);
			this->openFileButton->MaximumSize = System::Drawing::Size(300, 100);
			this->openFileButton->MinimumSize = System::Drawing::Size(150, 50);
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(150, 50);
			this->openFileButton->TabIndex = 1;
			this->openFileButton->Text = L"Открыть файл";
			this->openFileButton->UseVisualStyleBackColor = true;
			this->openFileButton->Click += gcnew System::EventHandler(this, &MainForm::openFileButton_Click);
			// 
			// mainMenuStrip
			// 
			this->mainMenuStrip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->mainMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenu,
					this->filtersToolStripMenu, this->additionalToolStripMenu
			});
			this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
			this->mainMenuStrip->Name = L"mainMenuStrip";
			this->mainMenuStrip->Size = System::Drawing::Size(884, 27);
			this->mainMenuStrip->TabIndex = 1;
			this->mainMenuStrip->Text = L"Главное меню";
			// 
			// fileToolStripMenu
			// 
			this->fileToolStripMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newFileToolStripMenuItem,
					this->openFileToolStripMenuItem, this->saveFileToolStripMenuItem, this->saveAsToolStripMenuItem
			});
			this->fileToolStripMenu->Name = L"fileToolStripMenu";
			this->fileToolStripMenu->Size = System::Drawing::Size(53, 23);
			this->fileToolStripMenu->Text = L"Файл";
			// 
			// newFileToolStripMenuItem
			// 
			this->newFileToolStripMenuItem->Name = L"newFileToolStripMenuItem";
			this->newFileToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->newFileToolStripMenuItem->Text = L"Создать";
			this->newFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::createNewFileButton_Click);
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->openFileToolStripMenuItem->Text = L"Открыть";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openFileButton_Click);
			// 
			// saveFileToolStripMenuItem
			// 
			this->saveFileToolStripMenuItem->Enabled = false;
			this->saveFileToolStripMenuItem->Name = L"saveFileToolStripMenuItem";
			this->saveFileToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->saveFileToolStripMenuItem->Text = L"Сохранить";
			this->saveFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveFileToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Enabled = false;
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->saveAsToolStripMenuItem->Text = L"Сохранить как";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveAsToolStripMenuItem_Click);
			// 
			// filtersToolStripMenu
			// 
			this->filtersToolStripMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->pressureFilterToolStripMenuItem,
					this->healthStateFilterToolStripMenuItem, this->pulseFilterToolStripMenuItem
			});
			this->filtersToolStripMenu->Enabled = false;
			this->filtersToolStripMenu->Name = L"filtersToolStripMenu";
			this->filtersToolStripMenu->Size = System::Drawing::Size(77, 23);
			this->filtersToolStripMenu->Text = L"Фильтры";
			// 
			// pressureFilterToolStripMenuItem
			// 
			this->pressureFilterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->morningToolStripMenuItem,
					this->dayToolStripMenuItem, this->eveningToolStripMenuItem, this->nightToolStripMenuItem
			});
			this->pressureFilterToolStripMenuItem->Name = L"pressureFilterToolStripMenuItem";
			this->pressureFilterToolStripMenuItem->Size = System::Drawing::Size(208, 24);
			this->pressureFilterToolStripMenuItem->Text = L"Давление";
			// 
			// morningToolStripMenuItem
			// 
			this->morningToolStripMenuItem->CheckOnClick = true;
			this->morningToolStripMenuItem->Name = L"morningToolStripMenuItem";
			this->morningToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->morningToolStripMenuItem->Text = L"Утреннее";
			this->morningToolStripMenuItem->ToolTipText = L"Показывать записи только с утренним давлением";
			this->morningToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::morningToolStripMenuItem_CheckedChanged);
			// 
			// dayToolStripMenuItem
			// 
			this->dayToolStripMenuItem->CheckOnClick = true;
			this->dayToolStripMenuItem->Name = L"dayToolStripMenuItem";
			this->dayToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->dayToolStripMenuItem->Text = L"Дневное";
			this->dayToolStripMenuItem->ToolTipText = L"Показывать записи только с дневным давлением";
			this->dayToolStripMenuItem->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::dayToolStripMenuItem_CheckStateChanged);
			// 
			// eveningToolStripMenuItem
			// 
			this->eveningToolStripMenuItem->CheckOnClick = true;
			this->eveningToolStripMenuItem->Name = L"eveningToolStripMenuItem";
			this->eveningToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->eveningToolStripMenuItem->Text = L"Вечернее";
			this->eveningToolStripMenuItem->ToolTipText = L"Показывать записи только с вечерним давлением";
			this->eveningToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::eveningToolStripMenuItem_CheckedChanged);
			// 
			// nightToolStripMenuItem
			// 
			this->nightToolStripMenuItem->CheckOnClick = true;
			this->nightToolStripMenuItem->Name = L"nightToolStripMenuItem";
			this->nightToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->nightToolStripMenuItem->Text = L"Ночное";
			this->nightToolStripMenuItem->ToolTipText = L"Показывать записи только с ночным давлением";
			this->nightToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::nightToolStripMenuItem_CheckedChanged);
			// 
			// healthStateFilterToolStripMenuItem
			// 
			this->healthStateFilterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->goodToolStripMenuItem,
					this->satisfactoryToolStripMenuItem, this->unsatisfactoryToolStripMenuItem
			});
			this->healthStateFilterToolStripMenuItem->Name = L"healthStateFilterToolStripMenuItem";
			this->healthStateFilterToolStripMenuItem->Size = System::Drawing::Size(208, 24);
			this->healthStateFilterToolStripMenuItem->Text = L"Состояние здоровья";
			// 
			// goodToolStripMenuItem
			// 
			this->goodToolStripMenuItem->CheckOnClick = true;
			this->goodToolStripMenuItem->Name = L"goodToolStripMenuItem";
			this->goodToolStripMenuItem->Size = System::Drawing::Size(219, 24);
			this->goodToolStripMenuItem->Text = L"Хорошо";
			this->goodToolStripMenuItem->ToolTipText = L"хорошим состоянием здоровья";
			this->goodToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::goodToolStripMenuItem_CheckedChanged);
			// 
			// satisfactoryToolStripMenuItem
			// 
			this->satisfactoryToolStripMenuItem->CheckOnClick = true;
			this->satisfactoryToolStripMenuItem->Name = L"satisfactoryToolStripMenuItem";
			this->satisfactoryToolStripMenuItem->Size = System::Drawing::Size(219, 24);
			this->satisfactoryToolStripMenuItem->Text = L"Удовлетворительно";
			this->satisfactoryToolStripMenuItem->ToolTipText = L"Показывать записи только с удовлетворительным состоянием здоровья";
			this->satisfactoryToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::satisfactoryToolStripMenuItem_CheckedChanged);
			// 
			// unsatisfactoryToolStripMenuItem
			// 
			this->unsatisfactoryToolStripMenuItem->CheckOnClick = true;
			this->unsatisfactoryToolStripMenuItem->Name = L"unsatisfactoryToolStripMenuItem";
			this->unsatisfactoryToolStripMenuItem->Size = System::Drawing::Size(219, 24);
			this->unsatisfactoryToolStripMenuItem->Text = L"Неудовлетворительно";
			this->unsatisfactoryToolStripMenuItem->ToolTipText = L"Показывать записи только с неудовлетворительным состоянием здоровья";
			this->unsatisfactoryToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::unsatisfactoryToolStripMenuItem_CheckedChanged);
			// 
			// pulseFilterToolStripMenuItem
			// 
			this->pulseFilterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->higher120ToolStripMenuItem });
			this->pulseFilterToolStripMenuItem->Name = L"pulseFilterToolStripMenuItem";
			this->pulseFilterToolStripMenuItem->Size = System::Drawing::Size(208, 24);
			this->pulseFilterToolStripMenuItem->Text = L"Пульс";
			// 
			// higher120ToolStripMenuItem
			// 
			this->higher120ToolStripMenuItem->CheckOnClick = true;
			this->higher120ToolStripMenuItem->Name = L"higher120ToolStripMenuItem";
			this->higher120ToolStripMenuItem->Size = System::Drawing::Size(142, 24);
			this->higher120ToolStripMenuItem->Text = L"Выше 120";
			this->higher120ToolStripMenuItem->ToolTipText = L"Показывать записи только с пульсом выше 120";
			this->higher120ToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::higher120ToolStripMenuItem_CheckedChanged);
			// 
			// additionalToolStripMenu
			// 
			this->additionalToolStripMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->oneMonthPressurePlotToolStripMenuItem,
					this->pressureRatioToolStripMenuItem
			});
			this->additionalToolStripMenu->Enabled = false;
			this->additionalToolStripMenu->Name = L"additionalToolStripMenu";
			this->additionalToolStripMenu->Size = System::Drawing::Size(121, 23);
			this->additionalToolStripMenu->Text = L"Дополнительно";
			// 
			// oneMonthPressurePlotToolStripMenuItem
			// 
			this->oneMonthPressurePlotToolStripMenuItem->Name = L"oneMonthPressurePlotToolStripMenuItem";
			this->oneMonthPressurePlotToolStripMenuItem->Size = System::Drawing::Size(413, 24);
			this->oneMonthPressurePlotToolStripMenuItem->Text = L"График давления за последние 30 дней";
			this->oneMonthPressurePlotToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::oneMonthPressurePlotToolStripMenuItem_Click);
			// 
			// pressureRatioToolStripMenuItem
			// 
			this->pressureRatioToolStripMenuItem->Name = L"pressureRatioToolStripMenuItem";
			this->pressureRatioToolStripMenuItem->Size = System::Drawing::Size(413, 24);
			this->pressureRatioToolStripMenuItem->Text = L"Соотношение дней гипертонии, гипотонии и нормы";
			this->pressureRatioToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pressureRatioToolStripMenuItem_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"bin";
			this->openFileDialog->Filter = L"Бинарные файлы|*.bin";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->DefaultExt = L"bin";
			this->saveFileDialog->Filter = L"Бинарные файлы|*.bin";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 361);
			this->Controls->Add(this->mainTabControl);
			this->Controls->Add(this->mainMenuStrip);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->mainMenuStrip;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(900, 400);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Контроль давления пациента";
			this->mainTabControl->ResumeLayout(false);
			this->initialTabPage->ResumeLayout(false);
			this->initialPanel->ResumeLayout(false);
			this->initialPanel->PerformLayout();
			this->mainMenuStrip->ResumeLayout(false);
			this->mainMenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/// <summary>
		/// Вывод MessageBox с ошибкой сохранения пустого файла.
		/// </summary>
		void ShowEmptyFileSaveErrorMessage() {
			MessageBox::Show(this, "Чтобы сохранить файл, в нём должна находится хотя бы одна запись.", "Не удалось сохранить файл",
				MessageBoxButtons::OK,
				MessageBoxIcon::Stop);
		}

		/// <summary>
		/// Создание новой вкладки с текстом <paramref name="tabPageText"/> и таблицей, сохранённой по пути <paramref name="filePath"/>.
		/// </summary>
		void AddNewTabPageWithNewTable(String^ tabPageText, String^ filePath)
		{
			// Создаём новую вкладку с текстом - названием файла
			TabPage^ newTabPage = gcnew TabPage(tabPageText);

			newTabPage->Name = String::Format("{0}TabPage", tabPageText);

			// Создаём новую таблицу из файла, добавляем её во вкладку
			EntryTableUserControl^ entryTable = gcnew EntryTableUserControl(filePath);
			entryTable->Dock = DockStyle::Fill;
			newTabPage->Controls->Add(entryTable);

			// Добавляем и выбираем новую вкладку
			mainTabControl->TabPages->Add(newTabPage);
			mainTabControl->SelectTab(newTabPage->Name);
		}

		/// <summary>
		/// Удалить вкладку уже открытого файл в случае его перезаписи
		/// с другой таблицей. При этом выбранная вкладка переименовывается 
		/// его именем.
		/// </summary>
		void RemoveOverwritedFileTab(String^ pathToOverwritedFile) 
		{
			String^ overwritedFileName = Path::GetFileNameWithoutExtension(pathToOverwritedFile);
			// Проверка на открытую вкладку перезаписываемого файла.
			// Закрываем её, если она есть.
			for (int i = 0; i < mainTabControl->TabCount; i++)
			{
				if (i != mainTabControl->SelectedIndex &&
					mainTabControl->TabPages[i]->Text->Equals(overwritedFileName))
				{
					mainTabControl->TabPages->RemoveAt(i);
				}
			}
			mainTabControl->SelectedTab->ResetText();
			mainTabControl->SelectedTab->Text = overwritedFileName;
		}

		/// <summary>
		/// Снять флаг со всех предметов во всём меню, кроме <paramref name="untouchable"/>
		/// и его владельца.
		/// </summary>
		/// <param name="untouchable">Предмет, с которого не будет сниматься флаг.</param>
		void UncheckOtherFilterToolStripMenuItems(ToolStripMenuItem^ untouchable) 
		{
			auto currentOwner = (ToolStripMenuItem^)untouchable->OwnerItem;
			for each (ToolStripMenuItem^ parentMenuItem in filtersToolStripMenu->DropDownItems)
			{
				if (!parentMenuItem->Equals(currentOwner) && parentMenuItem->Checked)
				{
					parentMenuItem->Checked = false;
				}

				for each (ToolStripMenuItem^ childMenuItem in parentMenuItem->DropDownItems)
				{
					if (!childMenuItem->Equals(untouchable) && childMenuItem->Checked)
					{
						childMenuItem->Checked = false;
					}
				}
			}
		}

		/// <summary>
		/// Находится ли во всём меню фильтров хотя бы ещё один помеченный элемент,
		/// кроме <paramref name="untouchable"/>.
		/// </summary>
		bool IsOtherFilterToolStripMenuItemsChecked(ToolStripMenuItem^ untouchable) 
		{
			auto currentOwner = (ToolStripMenuItem^)untouchable->OwnerItem;
			for each (ToolStripMenuItem^ parentMenuItem in filtersToolStripMenu->DropDownItems)
			{
				if (!parentMenuItem->Equals(currentOwner) && parentMenuItem->Checked)
				{
					return true;
				}

				for each (ToolStripMenuItem^ childMenuItem in parentMenuItem->DropDownItems)
				{
					if (!childMenuItem->Equals(untouchable) && childMenuItem->Checked)
					{
						return true;
					}
				}
			}
			return false;
		}

		/// <summary>
		/// Получить объект DataGridView из текущей выбранной вкладки
		/// </summary>
		DataGridView^ GetDataGridViewFromSelectedTab() 
		{
			// Индекс DataGridView в TableLayoutPanel, которая находится в EntryTableUserControl
			const int dataGridViewIndex = 2;

			// Получаем EntryTableUserControl в выбранной вкладке
			auto currentEntryTableUserControl = (EntryTableUserControl^)mainTabControl->SelectedTab->Controls["EntryTableUserControl"];

			// Получаем DataGrid из TableLayoutPanel в EntryTable по индексу
			return (DataGridView^)currentEntryTableUserControl->Controls["TableLayoutPanel"]->Controls[dataGridViewIndex];
		}

		/// <summary>
		/// Скрываем все строки <paramref name="dataGridView"/>, для которых выполняется
		/// условие <paramref name="predicate"/>.
		/// </summary>
		void HideAllFilteredEntries(DataGridView^ dataGridView, Predicate<DataGridViewCellCollection^>^ predicate)
		{
			// Без этого при скрытии 0 строки вылетит странная ошибка
			dataGridView->CurrentCell = nullptr;
			for each (DataGridViewRow^ row in dataGridView->Rows)
			{
				if (predicate(row->Cells))
				{
					row->Visible = false;
				}
			}
		}

		/// <summary>
		/// Если <paramref name="filterMenuSubSubItem"/> помечен, офильтровываем все строки 
		/// DataGridView текущей вкладки, для которых выполняется
		/// условие <paramref name="predicate"/>, и помечаем его родительский
		/// элемент. Иначе делаем все строки видимыми и снимаем флаг с родительского,
		/// если ни один его элемент не помечен.
		/// </summary>
		void FilterByToolStripMenuItem(ToolStripMenuItem^ filterMenuSubSubItem,
			Predicate<DataGridViewCellCollection^>^ predicate) 
		{
			auto currentTable = (EntryTableUserControl^)mainTabControl->SelectedTab->Controls["EntryTableUserControl"];
			auto dataGridView = GetDataGridViewFromSelectedTab();
			auto parentMenuItem = (ToolStripMenuItem^)filterMenuSubSubItem->OwnerItem;

			if (filterMenuSubSubItem->Checked)
			{
				parentMenuItem->Checked = true;
				currentTable->IsFilterActive = true;
				// Если предмет помечается, когда уже есть помеченный, необходимо сделать 
				// и только потом снять флаг с уже помеченного
				if (IsOtherFilterToolStripMenuItemsChecked(filterMenuSubSubItem))
				{
					for each (DataGridViewRow ^ row in dataGridView->Rows)
					{
						row->Visible = true;
					}
				}
				UncheckOtherFilterToolStripMenuItems(filterMenuSubSubItem);
				HideAllFilteredEntries(dataGridView, predicate);
			}
			// Если с предмета сняли флаг и больше ни одного предмета в меню не было
			// помечено, открываем все строки и снимаем флаг с родителя
			else if (!filterMenuSubSubItem->Checked && !IsOtherFilterToolStripMenuItemsChecked(filterMenuSubSubItem))
			{
				for each (DataGridViewRow ^ row in dataGridView->Rows)
				{
					row->Visible = true;
				}

				parentMenuItem->Checked = false;
				currentTable->IsFilterActive = false;
			}
		}


/// <summary>
///  Создание новой вкладки для нового файла
/// </summary>
private: System::Void createNewFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Создаём название и текст вкладки с нумерацией
		String^ newTabPageText = String::Format("Без названия{0}", _newTabPageCounter);
		String^ newTabPageName = String::Format("newTabPage{0}", _newTabPageCounter);

		// Создаём вкладку
		TabPage^ newTabPage = gcnew TabPage(newTabPageText);
		newTabPage->Name = newTabPageName;
		// Создаём в ней пустую таблицу, добавляем вкладку 
		// в mainTabControl и открываем
		EntryTableUserControl^ entryTable = gcnew EntryTableUserControl();
		entryTable->Dock = DockStyle::Fill;
		newTabPage->Controls->Add(entryTable);

		mainTabControl->TabPages->Add(newTabPage);
		mainTabControl->SelectTab(newTabPageName);

		_newTabPageCounter++;
	}

#pragma region События с mainTabControl
/// <summary>
/// Делаем активными/неактивными опции меню, которые нужны только для открытого файла
/// </summary>
private: System::Void mainTabControl_Selected(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e) 
{
	
	if (e->TabPage->Name == "initialTabPage")
	{
		saveFileToolStripMenuItem->Enabled = false;
		saveAsToolStripMenuItem->Enabled = false;
		filtersToolStripMenu->Enabled = false;
		additionalToolStripMenu->Enabled = false;
	}
	else
	{
		saveFileToolStripMenuItem->Enabled = true;
		saveAsToolStripMenuItem->Enabled = true;
		filtersToolStripMenu->Enabled = true;
		additionalToolStripMenu->Enabled = true;
	}
}

// TODO: СОБЫТИЕ - НАЖАТИЕ ПКМ НА TABPAGE 
// С ВЫВОДОМ СПИСКА: УДАЛИТЬ, ПЕРЕИМЕНОВАТЬ

#pragma endregion

#pragma region События с меню "Файл"
/// <summary>
/// Открытие существующего файла.
/// </summary>
private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
	{
		return;
	}

	// Получаем относительное имя файла
	String^ fileName = Path::GetFileNameWithoutExtension(openFileDialog->FileName);

	// Проверка на наличие уже открытого этого же файла
	for (size_t i = 0; i < mainTabControl->TabCount; i++)
	{
		auto currentTable = (EntryTableUserControl^)mainTabControl->TabPages[i]->Controls["EntryTableUserControl"];
		if (currentTable != nullptr)
		{
			// ЕСЛИ создать новую вкладу "1" с именем "Безымянный1" и 
			// попробовать открыть другой файл с таким именем, откроется
			// ещё одна вкладка "2" с таким же именем "Безымянный1".
			// Скорее всего надо предлагать сохранять вкладку "1", и дальше 
			// что-нибудь ещё делать, может быть закрывать её и открывать "2"
			if (openFileDialog->FileName->Equals(currentTable->SavedFilePath))
			{
				MessageBox::Show(this,
					String::Format("Файл {0} уже открыт.", fileName),
					"Ошибка открытия файла",
					MessageBoxButtons::OK,
					MessageBoxIcon::Stop);
				return;
			}
		}
		
	}

	AddNewTabPageWithNewTable(fileName, openFileDialog->FileName);
}

/// <summary>
/// Сохранение файла.
/// </summary>
private: System::Void saveFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	auto currentTable = (EntryTableUserControl^)mainTabControl->SelectedTab->Controls["EntryTableUserControl"];

	// Если файл ни разу не сохраняли, создаём его через
	// диалог сохранения файла для выбора пути
	if (!currentTable->IsSavedOnce)
	{
		// Если таблица заполнена, создаём файл
		if (currentTable->IsFilled)
		{
			// В качестве стандартного имени выбираем имя закладки
			saveFileDialog->FileName = mainTabControl->SelectedTab->Text;

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
			{
				return;
			}

			String^ filePath = saveFileDialog->FileName;

			// Если перезапись файла, то меняем текст вкладки на имя
			// перезаписываемого файла
			if (File::Exists(filePath))
			{
				RemoveOverwritedFileTab(filePath);
			}
			
			// Меняем название вкладки на название сохранённого файла
			mainTabControl->SelectedTab->ResetText();
			mainTabControl->SelectedTab->Text = Path::GetFileNameWithoutExtension(filePath);
			currentTable->CreateFileWithTable(filePath);
		}
		// Если не заполнена, выбрасываем сообщение
		else
		{
			ShowEmptyFileSaveErrorMessage();
		}
	}
	// Иначе сохраняем изменённую таблицу в тот же файл
	// без вызова диалога
	else
	{
		if (currentTable->IsFilled)
		{
			currentTable->SaveTableToFile();
		}
		else
		{
			ShowEmptyFileSaveErrorMessage();
		}
	}
}

/// <summary>
/// "Сохранить как". Сохранение файла с другими параметрами (другой путь, имя).
/// </summary>
private: System::Void saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto currentTable = (EntryTableUserControl^)mainTabControl->SelectedTab->Controls["EntryTableUserControl"];

	if (currentTable->IsFilled)
	{
		// В качестве стандартного имени выбираем имя закладки
		saveFileDialog->FileName = mainTabControl->SelectedTab->Text;

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		String^ filePath = saveFileDialog->FileName;
		String^ fileName = Path::GetFileNameWithoutExtension(filePath);

		// Если выбрана перезапись файла, то новую вкладку не надо создавать
		if (File::Exists(filePath))
		{
			// Проверка на уже открытый перезаписываемый файл. Его вкладку надо закрывать
			RemoveOverwritedFileTab(filePath);
			currentTable->CreateFileWithTable(filePath);
			return;
		}

		// Создаём файл с новым расположением
		currentTable->CreateFileWithTable(filePath);

		// Закрываем безымянную вкладку
		mainTabControl->TabPages->RemoveAt(mainTabControl->SelectedIndex);
		// И создаём новую с выбранным именем
		AddNewTabPageWithNewTable(fileName, filePath);
	}
	else
	{
		ShowEmptyFileSaveErrorMessage();
	}
}

#pragma endregion
		
#pragma region События с меню "Фильтры"
/// <summary>
/// При пометке флага "Утреннее" фильтруем по нему.
/// </summary>
private: System::Void morningToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(morningToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByMorningPressure));
}

/// <summary>
/// При пометке флага "Дневное" фильтруем по нему.
/// </summary>
private: System::Void dayToolStripMenuItem_CheckStateChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(dayToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByDayPressure));
}

/// <summary>
/// При пометке флага "Вечернее" фильтруем по нему.
/// </summary>
private: System::Void eveningToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(eveningToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByEveningPressure));
}
	   
/// <summary>
/// При пометке флага "Ночное" фильтруем по нему.
/// </summary>
private: System::Void nightToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(nightToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByNightPressure));
}

/// <summary>
/// При пометке флага "Хорошее" фильтруем по нему.
/// </summary>
private: System::Void goodToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(goodToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByGoodHealthState));
}

/// <summary>
/// При пометке флага "Удовлетворительное" фильтруем по нему.
/// </summary>
private: System::Void satisfactoryToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(satisfactoryToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterBySatisfactoryHealthState));
}

/// <summary>
/// При пометке флага "Неудовлетворительное" фильтруем по нему.
/// </summary>
private: System::Void unsatisfactoryToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(unsatisfactoryToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByUnsatisfactoryHealthState));
}

/// <summary>
/// При пометке флага "Пульс выше 120" фильтруем по нему.
/// </summary>
private: System::Void higher120ToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FilterByToolStripMenuItem(higher120ToolStripMenuItem,
		gcnew Predicate<DataGridViewCellCollection^>(&FilterFunctions::FilterByPulseHigher120));
}

#pragma endregion

#pragma region События с меню "Дополнительное"
/// <summary>
/// Вывод графика давления за последние 30 дней отдельной формой.
/// </summary>
private: System::Void oneMonthPressurePlotToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	auto currentTable = (EntryTableUserControl^)mainTabControl->SelectedTab->Controls["EntryTableUserControl"];
	if (currentTable->IsFilled)
	{
		auto pressurePlotForm = gcnew PressurePlotForm(currentTable->EntryList);
		pressurePlotForm->Show();
	}
	else
	{
		MessageBox::Show(this, "Для открытия графика в таблице должна содержаться хотя бы одна запись.",
			"Ошибка открытия графика давления за последние 30 дней",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}

/// <summary>
/// Вывод графика соотношения гипертонии, гипотонии и нормы.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void pressureRatioToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	
	auto currentTable = (EntryTableUserControl^)mainTabControl->SelectedTab->Controls["EntryTableUserControl"];
	if (currentTable->IsFilled)
	{
		auto ratioForm = gcnew PressureRatioForm(currentTable->EntryList);
		ratioForm->Show();
	}
	else
	{
		MessageBox::Show(this, "Для открытия графика в таблице должна содержаться хотя бы одна запись.",
			"Ошибка открытия графика соотношения давлений",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}

#pragma endregion
};
}
