#pragma once
#include "HealthEntry.h"
#include "TimePeriod.h"

namespace Sketch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Linq;

	/// <summary>
	/// ����� � �������� �������� �� ��������� 30 ����.
	/// </summary>
	public ref class PressurePlotForm : public System::Windows::Forms::Form
	{
		List<HealthEntry^>^ _filteredList = gcnew List<HealthEntry^>();

	public:
		PressurePlotForm(BindingList<HealthEntry^>^ inputList)
		{
			InitializeComponent();
			FilterEntriesFromInputList(inputList);
			SortByDateTime(_filteredList);
			
			// ��������� ����� �� ������
			for (int i = 0; i < _filteredList->Count; i++)
			{
				auto entry = _filteredList[i];
				pressureChart->Series[0]->Points->AddXY(entry->RecordDate.Date, inputList[i]->Pressure.Systolic);

				pressureChart->Series[1]->Points->AddXY(entry->RecordDate.Date, inputList[i]->Pressure.Diastolic);
			}
		}

	protected:
		~PressurePlotForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ pressureChart;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pressureChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pressureChart))->BeginInit();
			this->SuspendLayout();
			// 
			// pressureChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->pressureChart->ChartAreas->Add(chartArea1);
			this->pressureChart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Alignment = System::Drawing::StringAlignment::Far;
			legend1->DockedToChartArea = L"ChartArea1";
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Left;
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->IsTextAutoFit = false;
			legend1->ItemColumnSpacing = 40;
			legend1->MaximumAutoSize = 30;
			legend1->Name = L"Legend1";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pressureChart->Legends->Add(legend1);
			this->pressureChart->Location = System::Drawing::Point(0, 0);
			this->pressureChart->Name = L"pressureChart";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->LegendText = L"������������� ��������";
			series1->Name = L"systolicSeries";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->LegendText = L"�������������� ��������";
			series2->Name = L"diastolicSeries";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			this->pressureChart->Series->Add(series1);
			this->pressureChart->Series->Add(series2);
			this->pressureChart->Size = System::Drawing::Size(784, 561);
			this->pressureChart->TabIndex = 0;
			this->pressureChart->Text = L"chart1";
			// 
			// PressurePlotForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->pressureChart);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"PressurePlotForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������ �������� �� ��������� 30 ����";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pressureChart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// ��������������� ������ ������� ������ �� ��������� 30 ����
		/// </summary>
		void FilterEntriesFromInputList(BindingList<HealthEntry^>^ inputList) 
		{
			auto to = DateTime::Now;
			// 30 ���� �����
			auto from = to.AddDays(-30);

			for (int i = 0; i < inputList->Count; i++)
			{
				auto entry = inputList[i];
				if (entry->RecordDate.Date >= from && entry->RecordDate.Date <= to &&
					entry->RecordTimePeriod == TimePeriod::����)
				{
					_filteredList->Add(entry);
				}
			}
		}

		/// <summary>
		/// ��������� ������ �� ���� �� �����������.
		/// </summary>
		void SortByDateTime(List<HealthEntry^>^ filteredList)
		{
			for (int i = 0; i < filteredList->Count; i++)
			{
				for (int j = 0; j < filteredList->Count - i - 1; j++)
				{
					if (filteredList[j]->RecordDate > filteredList[j + 1]->RecordDate)
					{
						auto tmp = filteredList[j];
						filteredList[j] = filteredList[j + 1];
						filteredList[j + 1] = tmp;
					}
				}
			}
		}
	};
}
