﻿#pragma once
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
	/// Форма с графиком давления за последние 30 дней.
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
			
			// Добавляем точки на график
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pressureChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pressureChart))->BeginInit();
			this->SuspendLayout();
			// 
			// pressureChart
			// 
			chartArea2->Name = L"ChartArea1";
			this->pressureChart->ChartAreas->Add(chartArea2);
			this->pressureChart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Alignment = System::Drawing::StringAlignment::Far;
			legend2->DockedToChartArea = L"ChartArea1";
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Left;
			legend2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend2->IsTextAutoFit = false;
			legend2->ItemColumnSpacing = 40;
			legend2->MaximumAutoSize = 30;
			legend2->Name = L"Legend1";
			legend2->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pressureChart->Legends->Add(legend2);
			this->pressureChart->Location = System::Drawing::Point(0, 0);
			this->pressureChart->Name = L"pressureChart";
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->LegendText = L"Систолическое давление";
			series3->Name = L"systolicSeries";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series4->BorderWidth = 3;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Color = System::Drawing::Color::Red;
			series4->Legend = L"Legend1";
			series4->LegendText = L"Даистолическое давление";
			series4->Name = L"diastolicSeries";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			this->pressureChart->Series->Add(series3);
			this->pressureChart->Series->Add(series4);
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
			this->Text = L"График давления за последние 30 дней";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pressureChart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// Отфильтровываем только дневные записи за последние 30 дней
		/// </summary>
		void FilterEntriesFromInputList(BindingList<HealthEntry^>^ inputList) 
		{
			auto to = DateTime::Now;
			// 30 дней назад
			auto from = to.AddDays(-30);

			for (int i = 0; i < inputList->Count; i++)
			{
				auto entry = inputList[i];
				if (entry->RecordDate.Date >= from && entry->RecordDate.Date <= to &&
					entry->RecordTimePeriod == TimePeriod::День)
				{
					_filteredList->Add(entry);
				}
			}
		}

		/// <summary>
		/// Сортируем список по дате по возрастанию.
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
