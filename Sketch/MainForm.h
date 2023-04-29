#pragma once
#include "HealthEntry.h"

namespace Sketch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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

	private: System::Windows::Forms::ToolStripMenuItem^ давлениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ состояниеЗдоровьяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ пульсToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ additionalToolStripMenu;


	private: System::Windows::Forms::ToolStripMenuItem^ утреннееToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ дневноеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вечернееToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удовлетворительноToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ неудовлетворительноToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выше120ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ графикДавленияЗаПоследние30ДнейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem;
	private: System::Windows::Forms::Panel^ initialPanel;
	private: System::Windows::Forms::Button^ createNewFileButton;
	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Label^ welcomeLabel;

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
			this->mainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->initialTabPage = (gcnew System::Windows::Forms::TabPage());
			this->initialPanel = (gcnew System::Windows::Forms::Panel());
			this->createNewFileButton = (gcnew System::Windows::Forms::Button());
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->mainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtersToolStripMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->давлениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->утреннееToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->дневноеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вечернееToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->состояниеЗдоровьяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удовлетворительноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->неудовлетворительноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->пульсToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выше120ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->additionalToolStripMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->графикДавленияЗаПоследние30ДнейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
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
			this->mainTabControl->Location = System::Drawing::Point(0, 27);
			this->mainTabControl->Name = L"mainTabControl";
			this->mainTabControl->SelectedIndex = 0;
			this->mainTabControl->Size = System::Drawing::Size(784, 334);
			this->mainTabControl->TabIndex = 0;
			this->mainTabControl->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &MainForm::mainTabControl_Selected);
			// 
			// initialTabPage
			// 
			this->initialTabPage->Controls->Add(this->initialPanel);
			this->initialTabPage->Location = System::Drawing::Point(4, 25);
			this->initialTabPage->Name = L"initialTabPage";
			this->initialTabPage->Padding = System::Windows::Forms::Padding(3);
			this->initialTabPage->Size = System::Drawing::Size(776, 305);
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
			this->initialPanel->Size = System::Drawing::Size(770, 299);
			this->initialPanel->TabIndex = 2;
			// 
			// createNewFileButton
			// 
			this->createNewFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->createNewFileButton->Location = System::Drawing::Point(180, 120);
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
			this->openFileButton->Location = System::Drawing::Point(435, 120);
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
			this->mainMenuStrip->Size = System::Drawing::Size(784, 27);
			this->mainMenuStrip->TabIndex = 1;
			this->mainMenuStrip->Text = L"Главное меню";
			// 
			// fileToolStripMenu
			// 
			this->fileToolStripMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newFileToolStripMenuItem,
					this->openFileToolStripMenuItem, this->saveFileToolStripMenuItem
			});
			this->fileToolStripMenu->Name = L"fileToolStripMenu";
			this->fileToolStripMenu->Size = System::Drawing::Size(53, 23);
			this->fileToolStripMenu->Text = L"Файл";
			// 
			// newFileToolStripMenuItem
			// 
			this->newFileToolStripMenuItem->Name = L"newFileToolStripMenuItem";
			this->newFileToolStripMenuItem->Size = System::Drawing::Size(145, 24);
			this->newFileToolStripMenuItem->Text = L"Создать";
			this->newFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::createNewFileButton_Click);
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(145, 24);
			this->openFileToolStripMenuItem->Text = L"Открыть";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openFileButton_Click);
			// 
			// saveFileToolStripMenuItem
			// 
			this->saveFileToolStripMenuItem->Enabled = false;
			this->saveFileToolStripMenuItem->Name = L"saveFileToolStripMenuItem";
			this->saveFileToolStripMenuItem->Size = System::Drawing::Size(145, 24);
			this->saveFileToolStripMenuItem->Text = L"Сохранить";
			// 
			// filtersToolStripMenu
			// 
			this->filtersToolStripMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->давлениеToolStripMenuItem,
					this->состояниеЗдоровьяToolStripMenuItem, this->пульсToolStripMenuItem
			});
			this->filtersToolStripMenu->Enabled = false;
			this->filtersToolStripMenu->Name = L"filtersToolStripMenu";
			this->filtersToolStripMenu->Size = System::Drawing::Size(77, 23);
			this->filtersToolStripMenu->Text = L"Фильтры";
			// 
			// давлениеToolStripMenuItem
			// 
			this->давлениеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->утреннееToolStripMenuItem,
					this->дневноеToolStripMenuItem, this->вечернееToolStripMenuItem
			});
			this->давлениеToolStripMenuItem->Name = L"давлениеToolStripMenuItem";
			this->давлениеToolStripMenuItem->Size = System::Drawing::Size(208, 24);
			this->давлениеToolStripMenuItem->Text = L"Давление";
			// 
			// утреннееToolStripMenuItem
			// 
			this->утреннееToolStripMenuItem->Name = L"утреннееToolStripMenuItem";
			this->утреннееToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->утреннееToolStripMenuItem->Text = L"Утреннее";
			// 
			// дневноеToolStripMenuItem
			// 
			this->дневноеToolStripMenuItem->Name = L"дневноеToolStripMenuItem";
			this->дневноеToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->дневноеToolStripMenuItem->Text = L"Дневное";
			// 
			// вечернееToolStripMenuItem
			// 
			this->вечернееToolStripMenuItem->Name = L"вечернееToolStripMenuItem";
			this->вечернееToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->вечернееToolStripMenuItem->Text = L"Вечернее";
			// 
			// состояниеЗдоровьяToolStripMenuItem
			// 
			this->состояниеЗдоровьяToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->удовлетворительноToolStripMenuItem,
					this->неудовлетворительноToolStripMenuItem
			});
			this->состояниеЗдоровьяToolStripMenuItem->Name = L"состояниеЗдоровьяToolStripMenuItem";
			this->состояниеЗдоровьяToolStripMenuItem->Size = System::Drawing::Size(208, 24);
			this->состояниеЗдоровьяToolStripMenuItem->Text = L"Состояние здоровья";
			// 
			// удовлетворительноToolStripMenuItem
			// 
			this->удовлетворительноToolStripMenuItem->Name = L"удовлетворительноToolStripMenuItem";
			this->удовлетворительноToolStripMenuItem->Size = System::Drawing::Size(219, 24);
			this->удовлетворительноToolStripMenuItem->Text = L"Удовлетворительно";
			// 
			// неудовлетворительноToolStripMenuItem
			// 
			this->неудовлетворительноToolStripMenuItem->Name = L"неудовлетворительноToolStripMenuItem";
			this->неудовлетворительноToolStripMenuItem->Size = System::Drawing::Size(219, 24);
			this->неудовлетворительноToolStripMenuItem->Text = L"Неудовлетворительно";
			// 
			// пульсToolStripMenuItem
			// 
			this->пульсToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->выше120ToolStripMenuItem });
			this->пульсToolStripMenuItem->Name = L"пульсToolStripMenuItem";
			this->пульсToolStripMenuItem->Size = System::Drawing::Size(208, 24);
			this->пульсToolStripMenuItem->Text = L"Пульс";
			// 
			// выше120ToolStripMenuItem
			// 
			this->выше120ToolStripMenuItem->Name = L"выше120ToolStripMenuItem";
			this->выше120ToolStripMenuItem->Size = System::Drawing::Size(142, 24);
			this->выше120ToolStripMenuItem->Text = L"Выше 120";
			// 
			// additionalToolStripMenu
			// 
			this->additionalToolStripMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->графикДавленияЗаПоследние30ДнейToolStripMenuItem,
					this->соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem
			});
			this->additionalToolStripMenu->Enabled = false;
			this->additionalToolStripMenu->Name = L"additionalToolStripMenu";
			this->additionalToolStripMenu->Size = System::Drawing::Size(121, 23);
			this->additionalToolStripMenu->Text = L"Дополнительно";
			// 
			// графикДавленияЗаПоследние30ДнейToolStripMenuItem
			// 
			this->графикДавленияЗаПоследние30ДнейToolStripMenuItem->Name = L"графикДавленияЗаПоследние30ДнейToolStripMenuItem";
			this->графикДавленияЗаПоследние30ДнейToolStripMenuItem->Size = System::Drawing::Size(413, 24);
			this->графикДавленияЗаПоследние30ДнейToolStripMenuItem->Text = L"График давления за последние 30 дней";
			// 
			// соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem
			// 
			this->соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem->Name = L"соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem";
			this->соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem->Size = System::Drawing::Size(413, 24);
			this->соотношениеДнейГипертонииГипотонииИНормыToolStripMenuItem->Text = L"Соотношение дней гипертонии, гипотонии и нормы";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// welcomeLabel
			// 
			this->welcomeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->welcomeLabel->AutoSize = true;
			this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->welcomeLabel->Location = System::Drawing::Point(285, 50);
			this->welcomeLabel->Name = L"welcomeLabel";
			this->welcomeLabel->Size = System::Drawing::Size(201, 25);
			this->welcomeLabel->TabIndex = 2;
			this->welcomeLabel->Text = L"Добро пожаловать";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 361);
			this->Controls->Add(this->mainTabControl);
			this->Controls->Add(this->mainMenuStrip);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->mainMenuStrip;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(800, 400);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
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

		// В user control вместе с таблицей
		List<HealthEntry^>^ entryList;

		// Счётчик новых вкладок
		int newTabPageCounter = 1;

		// Создание новой вкладки для нового файла
private: System::Void createNewFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ newTabPageText = String::Format("Без названия{0}", newTabPageCounter);
		String^ newTabPageName = String::Format("newTabPage{0}", newTabPageCounter);

		TabPage^ newTabPage = gcnew TabPage(newTabPageText);
		newTabPage->Name = newTabPageName;
		mainTabControl->TabPages->Add(newTabPage);
		mainTabControl->SelectTab(newTabPageName);
		newTabPageCounter++;

		// TODO: СОЗДАНИЕ НОВОЙ ПУСТОЙ ТАБЛИЦЫ

	}

		// TODO: СОБЫТИЕ - НАЖАТИЕ ПКМ НА TABPAGE 
		// С ВЫВОДОМ СПИСКА: УДАЛИТЬ, ПЕРЕИМЕНОВАТЬ

		// Делаем активными/неактивными опции меню, которые
		// нужны только для открытого файла	
private: System::Void mainTabControl_Selected(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e) 
{
	
	if (e->TabPage->Name == "initialTabPage")
	{
		saveFileToolStripMenuItem->Enabled = false;
		filtersToolStripMenu->Enabled = false;
		additionalToolStripMenu->Enabled = false;
	}
	else
	{
		saveFileToolStripMenuItem->Enabled = true;
		filtersToolStripMenu->Enabled = true;
		additionalToolStripMenu->Enabled = true;
	}
}

	   // Открытие существующего файла
private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
	{
		return;
	}

	// Высчитываем необходимые значения для получения
	// относительного имени файла
	int fileNameBeginningIndex = openFileDialog->FileName->LastIndexOf("\\") + 1;
	int extensionIndex = openFileDialog->FileName->LastIndexOf(".");
	int fileNameLength = extensionIndex - fileNameBeginningIndex;

	// Получаем относительное имя файла
	String^ fileName = openFileDialog->FileName->Substring(fileNameBeginningIndex, fileNameLength);

	// Создаём новую вкладку с текстом - названием файла
	// и выбираем её
	String^ newTabPageName = String::Format("{0}TabPage",  fileName);
	TabPage^ newTabPage = gcnew TabPage(fileName);
	newTabPage->Name = String::Format(newTabPageName);

	mainTabControl->TabPages->Add(newTabPage);
	mainTabControl->SelectTab(newTabPageName);

	// TODO: ЗАПОЛНЕНИЕ ТАБЛИЦЫ ДАННЫМИ ИЗ ФАЙЛА
	// И ДОБАВИТЬ ФИЛЬТР НА РАСШИРЕНИЕ
}
};
}
