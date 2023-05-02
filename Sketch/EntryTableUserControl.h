#pragma once
#include "HealthEntry.h"
#include "EntryEditorForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Sketch {

	/// <summary>
	/// ������� ��� ������� � �������� � ������������� ��� �� ��������������.
	/// </summary>
	public ref class EntryTableUserControl : public System::Windows::Forms::UserControl
	{
	public:
		/// <summary>
		/// �������� ������ �������.
		/// </summary>
		EntryTableUserControl(void)
		{
			InitializeComponent();
			EntryList = gcnew BindingList<HealthEntry^>();
			mainDataGridView->DataSource = EntryList;

			AdjustBindedColums();
		}

		/// <summary>
		/// �������� ������� �� ��� ������������� ������ (��������, �� �����).
		/// </summary>
		EntryTableUserControl(BindingList<HealthEntry^>^ entryList)
		{
			InitializeComponent();
			EntryList = entryList;
			mainDataGridView->DataSource = EntryList;
		}

		property BindingList<HealthEntry^>^ EntryList;

	protected:
		~EntryTableUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	private: System::Windows::Forms::DataGridView^ mainDataGridView;
	private: System::Windows::Forms::Button^ addEntryButton;
	private: System::Windows::Forms::Button^ deleteEntryButton;
	private: System::Windows::Forms::Button^ editEntryButton;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->deleteEntryButton = (gcnew System::Windows::Forms::Button());
			this->editEntryButton = (gcnew System::Windows::Forms::Button());
			this->mainDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->addEntryButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 2;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80)));
			this->tableLayoutPanel->Controls->Add(this->deleteEntryButton, 0, 2);
			this->tableLayoutPanel->Controls->Add(this->editEntryButton, 0, 1);
			this->tableLayoutPanel->Controls->Add(this->mainDataGridView, 1, 0);
			this->tableLayoutPanel->Controls->Add(this->addEntryButton, 0, 0);
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 3;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel->Size = System::Drawing::Size(870, 299);
			this->tableLayoutPanel->TabIndex = 0;
			// 
			// deleteEntryButton
			// 
			this->deleteEntryButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->deleteEntryButton->Location = System::Drawing::Point(10, 223);
			this->deleteEntryButton->Margin = System::Windows::Forms::Padding(10, 25, 10, 25);
			this->deleteEntryButton->Name = L"deleteEntryButton";
			this->deleteEntryButton->Size = System::Drawing::Size(154, 51);
			this->deleteEntryButton->TabIndex = 3;
			this->deleteEntryButton->Text = L"�������";
			this->deleteEntryButton->UseVisualStyleBackColor = true;
			this->deleteEntryButton->SizeChanged += gcnew System::EventHandler(this, &EntryTableUserControl::buttons_SizeChanged);
			this->deleteEntryButton->Click += gcnew System::EventHandler(this, &EntryTableUserControl::deleteEntryButton_Click);
			// 
			// editEntryButton
			// 
			this->editEntryButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->editEntryButton->Location = System::Drawing::Point(10, 124);
			this->editEntryButton->Margin = System::Windows::Forms::Padding(10, 25, 10, 25);
			this->editEntryButton->Name = L"editEntryButton";
			this->editEntryButton->Size = System::Drawing::Size(154, 49);
			this->editEntryButton->TabIndex = 2;
			this->editEntryButton->Text = L"�������������";
			this->editEntryButton->UseVisualStyleBackColor = true;
			this->editEntryButton->SizeChanged += gcnew System::EventHandler(this, &EntryTableUserControl::buttons_SizeChanged);
			this->editEntryButton->Click += gcnew System::EventHandler(this, &EntryTableUserControl::editEntryButton_Click);
			// 
			// mainDataGridView
			// 
			this->mainDataGridView->AllowUserToAddRows = false;
			this->mainDataGridView->AllowUserToDeleteRows = false;
			this->mainDataGridView->AllowUserToResizeColumns = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->mainDataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->mainDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mainDataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainDataGridView->Location = System::Drawing::Point(177, 3);
			this->mainDataGridView->Name = L"mainDataGridView";
			this->mainDataGridView->ReadOnly = true;
			this->mainDataGridView->RowHeadersVisible = false;
			this->mainDataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->tableLayoutPanel->SetRowSpan(this->mainDataGridView, 3);
			this->mainDataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->mainDataGridView->Size = System::Drawing::Size(690, 293);
			this->mainDataGridView->TabIndex = 0;
			// 
			// addEntryButton
			// 
			this->addEntryButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addEntryButton->Location = System::Drawing::Point(10, 25);
			this->addEntryButton->Margin = System::Windows::Forms::Padding(10, 25, 10, 25);
			this->addEntryButton->Name = L"addEntryButton";
			this->addEntryButton->Size = System::Drawing::Size(154, 49);
			this->addEntryButton->TabIndex = 1;
			this->addEntryButton->Text = L"�������";
			this->addEntryButton->UseVisualStyleBackColor = true;
			this->addEntryButton->SizeChanged += gcnew System::EventHandler(this, &EntryTableUserControl::buttons_SizeChanged);
			this->addEntryButton->Click += gcnew System::EventHandler(this, &EntryTableUserControl::addEntryButton_Click);
			// 
			// EntryTableUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel);
			this->MinimumSize = System::Drawing::Size(870, 299);
			this->Name = L"EntryTableUserControl";
			this->Size = System::Drawing::Size(870, 299);
			this->tableLayoutPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


private:
		/// <summary>
		/// ��������� ����������� �������, ����������� ��� ��������.
		/// </summary>
		System::Void AdjustBindedColums() 
		{
			mainDataGridView->Columns["RecordDate"]->MinimumWidth = 105;
			mainDataGridView->Columns["RecordDate"]->Width = 105;
			mainDataGridView->Columns["RecordDate"]->FillWeight = 105;
			mainDataGridView->Columns["RecordDate"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			mainDataGridView->Columns["RecordTimePeriod"]->MinimumWidth = 80;
			mainDataGridView->Columns["RecordTimePeriod"]->Width = 80;
			mainDataGridView->Columns["RecordTimePeriod"]->FillWeight = 80;
			mainDataGridView->Columns["RecordTimePeriod"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			mainDataGridView->Columns["HealthState"]->MinimumWidth = 155;
			mainDataGridView->Columns["HealthState"]->Width = 155;
			mainDataGridView->Columns["HealthState"]->FillWeight = 155;
			mainDataGridView->Columns["HealthState"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			mainDataGridView->Columns["Pressure"]->MinimumWidth = 90;
			mainDataGridView->Columns["Pressure"]->Width = 90;
			mainDataGridView->Columns["Pressure"]->FillWeight = 90;
			mainDataGridView->Columns["Pressure"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			mainDataGridView->Columns["Pulse"]->MinimumWidth = 60;
			mainDataGridView->Columns["Pulse"]->Width = 60;
			mainDataGridView->Columns["Pulse"]->FillWeight = 60;
			mainDataGridView->Columns["Pulse"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			mainDataGridView->Columns["Remark"]->MinimumWidth = 125;
			mainDataGridView->Columns["Remark"]->Width = 125;
			mainDataGridView->Columns["Remark"]->FillWeight = 125;
			mainDataGridView->Columns["Remark"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		}

		/// <summary>
		/// ���������� ��� ������ ��� ��������� ����� � ������ �����.
		/// </summary>
		/// � �������� ����������!!!!
		System::Void buttons_SizeChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		// ���������������� ����������� �����������
		const float buttonWidthScale = .08f;
		const float headerCellsWidthScale = .06f;

		// ����� ����� � ������ ������ ��� ������
		auto newButtonFont = gcnew System::Drawing::Font(
			addEntryButton->Font->FontFamily, 
			Math::Floor(addEntryButton->Width * buttonWidthScale),
			System::Drawing::GraphicsUnit::Point);

		addEntryButton->Font = newButtonFont;
		editEntryButton->Font = newButtonFont;
		deleteEntryButton->Font = newButtonFont;

		// ����� ����� � ������ ������ ��� ���������� ��������
		auto newHeaderCellsFont = gcnew System::Drawing::Font(
			addEntryButton->Font->FontFamily, 
			(float)Math::Floor(Math::Max(addEntryButton->Width * headerCellsWidthScale, 10.f)), 
			FontStyle::Bold, 
			System::Drawing::GraphicsUnit::Point);

		mainDataGridView->ColumnHeadersDefaultCellStyle->Font = newHeaderCellsFont;

	}

		/// <summary>
		/// ����� ���� ���������� ������.
		/// </summary>
		private: System::Void addEntryButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			auto addForm = gcnew EntryEditorForm(EntryList);

			addForm->ShowDialog();
		}
	
		/// <summary>
		/// �������� ���������� �������.
		/// </summary>
		private: System::Void deleteEntryButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (mainDataGridView->SelectedRows->Count == 0)
			{
				auto tip = gcnew ToolTip();
				tip->AutomaticDelay = 100;
				tip->Show(
						"�������� ��������� ������ ���� �����������\n���� ����� ������� � ������� ����� �������", 
						deleteEntryButton, 
						deleteEntryButton->Width / 2, 
						deleteEntryButton->Height / 2, 
						5000);
				return;
			}
			int selectedRowsCount = mainDataGridView->SelectedRows->Count;

			// ������������ ��������
			auto isDeleteAccepted = MessageBox::Show(this,
				String::Format("�� ����� ������ ������� ���������� ({0} ��) ������?", selectedRowsCount),
				"������������� �������� �������",
				MessageBoxButtons::YesNo, 
				MessageBoxIcon::Warning);
			
			if (isDeleteAccepted == DialogResult::Yes)
			{
				// ������� � ����� ����� �� ������� � ������������ ���������
				for (int i = selectedRowsCount - 1; i >= 0; i--)
				{
					EntryList->RemoveAt(mainDataGridView->SelectedRows[i]->Index);
				}
			}
		}

		/// <summary>
		/// ����� ���� �������������� ���������� ������.
		/// </summary>
		private: System::Void editEntryButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (mainDataGridView->SelectedRows->Count != 1)
			{
				auto tip = gcnew ToolTip();
				tip->AutomaticDelay = 100;
				tip->Show(
					"�������� ������ ���� ������ ���� ������� �� �� ����� ������� ����",
					editEntryButton,
					editEntryButton->Width / 2,
					editEntryButton->Height / 2,
					5000);
				return;
			}

			auto editForm = gcnew EntryEditorForm(EntryList, mainDataGridView->SelectedRows[0]->Index);
			editForm->ShowDialog();
		}
};
}
