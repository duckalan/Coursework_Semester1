#pragma once
#include "HealthEntry.h"
#include "TimePeriod.h"
#include "Pressure.h"
#include "HealthState.h"

namespace Sketch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Форма для создания или редактирования записей.
	/// </summary>
	public ref class EntryEditorForm : public System::Windows::Forms::Form
	{
		/// <summary>
		/// Список родительской формы. Передаём его в эту форму
		/// для добавления в него новых записей.
		/// </summary>
		BindingList<HealthEntry^>^ _parentEntryList;

		/// <summary>
		/// Показывает, открыта ли форма для редактирования уже существующей записи.
		/// </summary>
		bool isEditing = false;

		// Всплывающие подсказки при ошибках ввода
		ToolTip^ pressureToolTip = gcnew ToolTip();
		ToolTip^ pulseToolTip = gcnew ToolTip();
		ToolTip^ insertIndexToolTip = gcnew ToolTip();

	private: System::Windows::Forms::ComboBox^ insertIndexComboBox;

	public:
		/// <summary>
		/// Конструктор для создания новой записи в списке <paramref name="parentEntryList"/>.
		/// </summary>
		EntryEditorForm(BindingList<HealthEntry^>^ parentEntryList)
		{
			InitializeComponent();
			_parentEntryList = parentEntryList;

			// Значение по умолчанию
			insertIndexComboBox->SelectedItem = "Конец";

			// Биндим все значения перечислений в комбобоксы
			recordTimePeriodComboBox->DataSource = Enum::GetValues(TimePeriod::typeid);

			healthStateComboBox->DataSource = Enum::GetValues(HealthState::typeid);
		}

		/// <summary>
		/// Конструктор для передачи редактируемой записи с индексом <paramref name="entryIndex"/> в списке <paramref name="parentEntryList"/>.
		/// </summary>
		EntryEditorForm(BindingList<HealthEntry^>^ parentEntryList, int edittingEntryIndex) : EntryEditorForm(parentEntryList)
		{
			isEditing = true;

			// Меняем нужный текст
			Text = String::Format("Редактирование записи по индексу {0}", edittingEntryIndex);
			addAndExitButton->Text = "Изменить";

			// Скрываем панель для ввода индекса вставки.
			insertIndexPanel->Visible = false;

			// Устанавливаем в контролах значения переданной записи
			auto inputEntry = _parentEntryList[edittingEntryIndex];

			recordDateTimePicker->Value = inputEntry->RecordDate;

			// Здесь изменить выбранное значение можно только через
			// изменение индекса. Индекс получаем поиском строки,
			// которая является именем переданного перечисления
			auto recordTimePeriodInputIndex = recordTimePeriodComboBox->FindStringExact(Enum::GetName(TimePeriod::typeid, inputEntry->RecordTimePeriod));
			recordTimePeriodComboBox->SelectedIndex = recordTimePeriodInputIndex;

			auto healthStateInputIndex = healthStateComboBox->FindStringExact(Enum::GetName(HealthState::typeid, inputEntry->HealthState));
			healthStateComboBox->SelectedIndex = healthStateInputIndex;

			// Просто "= inputEntry->Pressure" нельзя, так все цифры
			// будут только в левой части маски перед /
			pressureMaskedTextBox->Text = inputEntry->Pressure.Systolic.ToString();
			pressureMaskedTextBox->Text += inputEntry->Pressure.Diastolic.ToString();

			pulseMaskedTextBox->Text = inputEntry->Pulse.ToString();
			remarkTextBox->Text = inputEntry->Remark;

			// Метод для парсинга один и тот же и для добавления, и для
			// редактирования. Данные для добавляемой (а значит и для
			// редактируемой) записи берутся из этого комбобокса.
			// По хорошему надо было как-то разделить эти формы
			insertIndexComboBox->Text = edittingEntryIndex.ToString();
		}


	protected:
		~EntryEditorForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ recordDateLabel;
	private: System::Windows::Forms::Label^ pulseLabel;
	private: System::Windows::Forms::Label^ pressureLabel;
	private: System::Windows::Forms::Label^ healthStateLabel;
	private: System::Windows::Forms::Label^ recordTimePeriodLabel;
	private: System::Windows::Forms::Label^ remarkLabel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TextBox^ remarkTextBox;
	private: System::Windows::Forms::ComboBox^ recordTimePeriodComboBox;
	private: System::Windows::Forms::ComboBox^ healthStateComboBox;
	private: System::Windows::Forms::DateTimePicker^ recordDateTimePicker;
	private: System::Windows::Forms::MaskedTextBox^ pressureMaskedTextBox;
	private: System::Windows::Forms::MaskedTextBox^ pulseMaskedTextBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ addAndExitButton;
	private: System::Windows::Forms::Panel^ insertIndexPanel;

	private: System::Windows::Forms::Label^ insertIndexLabel;

	private: System::Windows::Forms::Button^ cancelButton;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->remarkLabel = (gcnew System::Windows::Forms::Label());
			this->pulseLabel = (gcnew System::Windows::Forms::Label());
			this->pressureLabel = (gcnew System::Windows::Forms::Label());
			this->healthStateLabel = (gcnew System::Windows::Forms::Label());
			this->recordTimePeriodLabel = (gcnew System::Windows::Forms::Label());
			this->recordDateLabel = (gcnew System::Windows::Forms::Label());
			this->remarkTextBox = (gcnew System::Windows::Forms::TextBox());
			this->recordTimePeriodComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->healthStateComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->recordDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->pressureMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->pulseMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->addAndExitButton = (gcnew System::Windows::Forms::Button());
			this->insertIndexPanel = (gcnew System::Windows::Forms::Panel());
			this->insertIndexComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->insertIndexLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->insertIndexPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.96059F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.25507F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				26.17138F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				13.90986F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				9.770515F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15.9326F)));
			this->tableLayoutPanel1->Controls->Add(this->remarkLabel, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->pulseLabel, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->pressureLabel, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->healthStateLabel, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->recordTimePeriodLabel, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->recordDateLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->remarkTextBox, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->recordTimePeriodComboBox, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->healthStateComboBox, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->recordDateTimePicker, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pressureMaskedTextBox, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->pulseMaskedTextBox, 4, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 37.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 62.5F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(884, 200);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// remarkLabel
			// 
			this->remarkLabel->AutoSize = true;
			this->remarkLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->remarkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->remarkLabel->Location = System::Drawing::Point(751, 20);
			this->remarkLabel->Margin = System::Windows::Forms::Padding(10, 20, 10, 10);
			this->remarkLabel->Name = L"remarkLabel";
			this->remarkLabel->Size = System::Drawing::Size(123, 45);
			this->remarkLabel->TabIndex = 6;
			this->remarkLabel->Text = L"Примечание";
			this->remarkLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pulseLabel
			// 
			this->pulseLabel->AutoSize = true;
			this->pulseLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pulseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pulseLabel->Location = System::Drawing::Point(665, 20);
			this->pulseLabel->Margin = System::Windows::Forms::Padding(10, 20, 10, 10);
			this->pulseLabel->Name = L"pulseLabel";
			this->pulseLabel->Size = System::Drawing::Size(66, 45);
			this->pulseLabel->TabIndex = 5;
			this->pulseLabel->Text = L"Пульс";
			this->pulseLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pressureLabel
			// 
			this->pressureLabel->AutoSize = true;
			this->pressureLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pressureLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pressureLabel->Location = System::Drawing::Point(543, 20);
			this->pressureLabel->Margin = System::Windows::Forms::Padding(10, 20, 10, 10);
			this->pressureLabel->Name = L"pressureLabel";
			this->pressureLabel->Size = System::Drawing::Size(102, 45);
			this->pressureLabel->TabIndex = 4;
			this->pressureLabel->Text = L"Давление";
			this->pressureLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// healthStateLabel
			// 
			this->healthStateLabel->AutoSize = true;
			this->healthStateLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->healthStateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->healthStateLabel->Location = System::Drawing::Point(312, 20);
			this->healthStateLabel->Margin = System::Windows::Forms::Padding(10, 20, 10, 10);
			this->healthStateLabel->Name = L"healthStateLabel";
			this->healthStateLabel->Size = System::Drawing::Size(211, 45);
			this->healthStateLabel->TabIndex = 3;
			this->healthStateLabel->Text = L"Состояние здоровья";
			this->healthStateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// recordTimePeriodLabel
			// 
			this->recordTimePeriodLabel->AutoSize = true;
			this->recordTimePeriodLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->recordTimePeriodLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->recordTimePeriodLabel->Location = System::Drawing::Point(204, 20);
			this->recordTimePeriodLabel->Margin = System::Windows::Forms::Padding(10, 20, 10, 10);
			this->recordTimePeriodLabel->Name = L"recordTimePeriodLabel";
			this->recordTimePeriodLabel->Size = System::Drawing::Size(88, 45);
			this->recordTimePeriodLabel->TabIndex = 2;
			this->recordTimePeriodLabel->Text = L"Период записи";
			this->recordTimePeriodLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// recordDateLabel
			// 
			this->recordDateLabel->AutoSize = true;
			this->recordDateLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->recordDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->recordDateLabel->Location = System::Drawing::Point(10, 20);
			this->recordDateLabel->Margin = System::Windows::Forms::Padding(10, 20, 10, 10);
			this->recordDateLabel->Name = L"recordDateLabel";
			this->recordDateLabel->Size = System::Drawing::Size(174, 45);
			this->recordDateLabel->TabIndex = 1;
			this->recordDateLabel->Text = L"Дата записи";
			this->recordDateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// remarkTextBox
			// 
			this->remarkTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->remarkTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->remarkTextBox->Location = System::Drawing::Point(751, 78);
			this->remarkTextBox->Margin = System::Windows::Forms::Padding(10, 3, 10, 10);
			this->remarkTextBox->Multiline = true;
			this->remarkTextBox->Name = L"remarkTextBox";
			this->remarkTextBox->Size = System::Drawing::Size(123, 112);
			this->remarkTextBox->TabIndex = 10;
			// 
			// recordTimePeriodComboBox
			// 
			this->recordTimePeriodComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->recordTimePeriodComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->recordTimePeriodComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->recordTimePeriodComboBox->FormattingEnabled = true;
			this->recordTimePeriodComboBox->Location = System::Drawing::Point(204, 78);
			this->recordTimePeriodComboBox->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->recordTimePeriodComboBox->Name = L"recordTimePeriodComboBox";
			this->recordTimePeriodComboBox->Size = System::Drawing::Size(88, 26);
			this->recordTimePeriodComboBox->TabIndex = 11;
			// 
			// healthStateComboBox
			// 
			this->healthStateComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->healthStateComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->healthStateComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->healthStateComboBox->FormattingEnabled = true;
			this->healthStateComboBox->Location = System::Drawing::Point(312, 78);
			this->healthStateComboBox->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->healthStateComboBox->Name = L"healthStateComboBox";
			this->healthStateComboBox->Size = System::Drawing::Size(211, 26);
			this->healthStateComboBox->TabIndex = 12;
			// 
			// recordDateTimePicker
			// 
			this->recordDateTimePicker->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->recordDateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->recordDateTimePicker->Location = System::Drawing::Point(10, 78);
			this->recordDateTimePicker->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->recordDateTimePicker->Name = L"recordDateTimePicker";
			this->recordDateTimePicker->Size = System::Drawing::Size(174, 24);
			this->recordDateTimePicker->TabIndex = 13;
			// 
			// pressureMaskedTextBox
			// 
			this->pressureMaskedTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pressureMaskedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->pressureMaskedTextBox->Location = System::Drawing::Point(543, 78);
			this->pressureMaskedTextBox->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->pressureMaskedTextBox->Mask = L"000\\/000";
			this->pressureMaskedTextBox->Name = L"pressureMaskedTextBox";
			this->pressureMaskedTextBox->PromptChar = ' ';
			this->pressureMaskedTextBox->Size = System::Drawing::Size(102, 24);
			this->pressureMaskedTextBox->TabIndex = 14;
			this->pressureMaskedTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pulseMaskedTextBox
			// 
			this->pulseMaskedTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pulseMaskedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->pulseMaskedTextBox->Location = System::Drawing::Point(665, 78);
			this->pulseMaskedTextBox->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->pulseMaskedTextBox->Mask = L"000";
			this->pulseMaskedTextBox->Name = L"pulseMaskedTextBox";
			this->pulseMaskedTextBox->PromptChar = ' ';
			this->pulseMaskedTextBox->Size = System::Drawing::Size(66, 24);
			this->pulseMaskedTextBox->TabIndex = 15;
			this->pulseMaskedTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->cancelButton);
			this->panel1->Controls->Add(this->addAndExitButton);
			this->panel1->Controls->Add(this->insertIndexPanel);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 203);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(884, 158);
			this->panel1->TabIndex = 1;
			// 
			// cancelButton
			// 
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cancelButton->Location = System::Drawing::Point(492, 86);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(250, 50);
			this->cancelButton->TabIndex = 2;
			this->cancelButton->Text = L"Отмена";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &EntryEditorForm::cancelButton_Click);
			// 
			// addAndExitButton
			// 
			this->addAndExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addAndExitButton->Location = System::Drawing::Point(142, 86);
			this->addAndExitButton->Name = L"addAndExitButton";
			this->addAndExitButton->Size = System::Drawing::Size(250, 50);
			this->addAndExitButton->TabIndex = 1;
			this->addAndExitButton->Text = L"Добавить";
			this->addAndExitButton->UseVisualStyleBackColor = true;
			this->addAndExitButton->Click += gcnew System::EventHandler(this, &EntryEditorForm::addAndExitButton_Click);
			// 
			// insertIndexPanel
			// 
			this->insertIndexPanel->Controls->Add(this->insertIndexComboBox);
			this->insertIndexPanel->Controls->Add(this->insertIndexLabel);
			this->insertIndexPanel->Location = System::Drawing::Point(279, 20);
			this->insertIndexPanel->Name = L"insertIndexPanel";
			this->insertIndexPanel->Padding = System::Windows::Forms::Padding(5);
			this->insertIndexPanel->Size = System::Drawing::Size(325, 40);
			this->insertIndexPanel->TabIndex = 0;
			// 
			// insertIndexComboBox
			// 
			this->insertIndexComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->insertIndexComboBox->FormattingEnabled = true;
			this->insertIndexComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Начало", L"Конец" });
			this->insertIndexComboBox->Location = System::Drawing::Point(228, 7);
			this->insertIndexComboBox->Name = L"insertIndexComboBox";
			this->insertIndexComboBox->Size = System::Drawing::Size(85, 28);
			this->insertIndexComboBox->TabIndex = 1;
			// 
			// insertIndexLabel
			// 
			this->insertIndexLabel->AutoSize = true;
			this->insertIndexLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->insertIndexLabel->Location = System::Drawing::Point(10, 10);
			this->insertIndexLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->insertIndexLabel->Name = L"insertIndexLabel";
			this->insertIndexLabel->Size = System::Drawing::Size(212, 20);
			this->insertIndexLabel->TabIndex = 0;
			this->insertIndexLabel->Text = L"Индекс места добавления";
			// 
			// EntryEditorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 361);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(900, 400);
			this->Name = L"EntryEditorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Добавление новой записи";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->insertIndexPanel->ResumeLayout(false);
			this->insertIndexPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// Преобразует пользовательский ввод в объект класса HealthEntry^ и даёт
		/// его индекс в списке.
		/// </summary>
		/// <param name="output">При успешном преобразовании содержит объект 
		/// с введёнными пользователем значениями полей.</param>
		/// <param name="outputInsertIndex">При успешном преобразовании содержит 
		/// индекс возвращаемого объекта в списке.</param>
		/// <returns>Возвращает значение, указывающее, успешно 
		/// ли выполнена операция.</returns>
		bool TryParseEntryFromInput(HealthEntry^% output, int% outputInsertIndex)
		{
			// Проверка ввода давления и пульса
			bool isInputValide = true;
			UInt16 systolic;
			UInt16 diastolic;
			UInt16 pulse;

			auto pressureStrings = pressureMaskedTextBox->Text->Split('/');
			auto isSystolicParsed = UInt16::TryParse(pressureStrings[0], systolic);
			auto isDiastolicParsed = UInt16::TryParse(pressureStrings[1], diastolic);
			auto isPulseParsed = UInt16::TryParse(pulseMaskedTextBox->Text, pulse);

			// Если не распарсено, значит поле пустое
			if (!isSystolicParsed || !isDiastolicParsed)
			{
				pressureToolTip->Show("Введите корректное \nзначение", pressureMaskedTextBox, 0, 20, 5000);
				isInputValide = false;
			}
			if (!isPulseParsed)
			{
				pulseToolTip->Show("Введите значение", pulseMaskedTextBox, 25, 20, 5000);
				isInputValide = false;
			}

			// Проверка индекса вставки
			int insertIndex;
			auto isInsertIndexNumber = int::TryParse(insertIndexComboBox->Text, insertIndex);

			if (!isInsertIndexNumber)
			{
				if (insertIndexComboBox->Text->Equals("Начало"))
				{
					insertIndex = 0;
				}
				else if (insertIndexComboBox->Text->Equals("Конец"))
				{
					insertIndex = _parentEntryList->Count;
				}
				else
				{
					auto errorStr = String::Format("Введите значение в пределах \nот 0 до {0} включительно", _parentEntryList->Count);

					insertIndexToolTip->Show(errorStr, insertIndexComboBox, 0, 20, 5000);
					isInputValide = false;
				}
			}
			else
			{
				if (insertIndex > _parentEntryList->Count ||
					insertIndex < 0)
				{
					auto errorStr = String::Format("Введите значение в пределах \nот 0 до {0} включительно", _parentEntryList->Count);

					insertIndexToolTip->Show(errorStr, insertIndexComboBox, 0, 20, 5000);
					isInputValide = false;
				}
			}

			// Если ввод проверен, получаем все введённые значения
			if (isInputValide)
			{
				auto recordDate = recordDateTimePicker->Value;

				auto recordTimePeriod = safe_cast<TimePeriod>(recordTimePeriodComboBox->SelectedValue);
				auto healthState = safe_cast<HealthState>(healthStateComboBox->SelectedValue);

				Pressure pressure(systolic, diastolic);
				auto remark = remarkTextBox->Text;

				outputInsertIndex = insertIndex;
				output = gcnew HealthEntry(recordDate, recordTimePeriod, pressure, pulse, healthState, remark);

				return true;
			}
			else
			{
				return false;
			}
		}

	/// <summary>
	/// Добавление записи в таблицу и список.
	/// </summary>
	private: System::Void addAndExitButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HealthEntry^ entry = nullptr;
		int index;
		if (TryParseEntryFromInput(entry, index))
		{
			if (isEditing)
			{
				_parentEntryList[index] = entry;
			}
			else
			{
				_parentEntryList->Insert(index, entry);
			}
			
			this->Close();
		}
	}

	private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}

	};
}
