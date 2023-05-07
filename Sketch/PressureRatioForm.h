#pragma once
#include "HealthEntry.h"

namespace Sketch 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ‘орма с процентным соотношением количества дней нормы, гипотонии и гипертонии.
	/// </summary>
	public ref class PressureRatioForm : public System::Windows::Forms::Form
	{
		BindingList<HealthEntry^>^ _entryList;

		/// <summary>
		/// —реднее систолическое давление.
		/// </summary>
		float _systolicAvg = 0;

		/// <summary>
		/// —реднее диастолическое давление.
		/// </summary>
		float _diastolicAvg = 0;

	public:
		PressureRatioForm(BindingList<HealthEntry^>^ inputList)
		{
			InitializeComponent();
			_entryList = inputList;
			CalcAveragePressure();
			
			// ƒобавл€ем точки
			ratioChart->Series[0]->Points->AddXY(" оличество дней гипертонии", GetHypertensionPressureDayCount());
			ratioChart->Series[0]->Points->AddXY(" оличество дней гипотонии", GetHypotensionPressureDayCount());
			ratioChart->Series[0]->Points->AddXY(" оличество дней нормы", GetNormalPressureDaysCount());

			// ќтображать значени€ Y в процентах
			ratioChart->Series[0]->Label = "#PERCENT{P}";
			// ¬ легенде отображать значени€ по X
			ratioChart->Series[0]->LegendText = "#VALX"; 

		}

	protected:
		~PressureRatioForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ ratioChart;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->ratioChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ratioChart))->BeginInit();
			this->SuspendLayout();
			// 
			// ratioChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->ratioChart->ChartAreas->Add(chartArea1);
			this->ratioChart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend1";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ratioChart->Legends->Add(legend1);
			this->ratioChart->Location = System::Drawing::Point(0, 0);
			this->ratioChart->Name = L"ratioChart";
			this->ratioChart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Pastel;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->ratioChart->Series->Add(series1);
			this->ratioChart->Size = System::Drawing::Size(784, 561);
			this->ratioChart->TabIndex = 0;
			this->ratioChart->Text = L"chart1";
			// 
			// PressureRatioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->ratioChart);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"PressureRatioForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PressureRatioForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ratioChart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// ѕодсчитать средние систолическое и диастолическое давлени€.
		/// </summary>
		void CalcAveragePressure() 
		{
			for (int i = 0; i < _entryList->Count; i++)
			{
				_systolicAvg += _entryList[i]->Pressure.Systolic;
				_diastolicAvg += _entryList[i]->Pressure.Diastolic;
			}
			_systolicAvg /= _entryList->Count;
			_diastolicAvg /= _entryList->Count;
		}

		/// <summary>
		/// ѕолучить количество дней, когда была гипертони€ (значение на 20 % и более выше среднего).
		/// </summary>
		int GetHypertensionPressureDayCount() 
		{
			int counter = 0;

			for (int i = 0; i < _entryList->Count; i++)
			{
				if ((float)_entryList[i]->Pressure.Systolic >= _systolicAvg * 1.2f
					|| (float)_entryList[i]->Pressure.Diastolic >= _diastolicAvg * 1.2f)
				{
					counter++;
				}
			}

			return counter;
		}

		/// <summary>
		/// ѕолучить количество дней, когда была гипотони€ (значение на 20 % и более ниже среднего).
		/// </summary>
		int GetHypotensionPressureDayCount()
		{
			int counter = 0;

			for (int i = 0; i < _entryList->Count; i++)
			{
				if ((float)_entryList[i]->Pressure.Systolic <= _systolicAvg * 0.8f
					|| (float)_entryList[i]->Pressure.Diastolic <= _diastolicAvg * 0.8f)
				{
					counter++;
				}
			}

			return counter;
		}

		/// <summary>
		/// ѕолучить количество дней, когда было нормальное давление 
		/// (в пределах от 80% до 120% от среднего значени€).
		/// </summary>
		int GetNormalPressureDaysCount() 
		{
			int counter = 0;

			for (int i = 0; i < _entryList->Count; i++)
			{
				auto systolic = (float)_entryList[i]->Pressure.Systolic;
				auto diastolic = (float)_entryList[i]->Pressure.Diastolic;

				if ((systolic > _systolicAvg * 0.8f && systolic < _systolicAvg * 1.2f)
					|| (diastolic > _diastolicAvg * 0.8f && diastolic < _diastolicAvg * 1.2f))
				{
					counter++;
				}
			}

			return counter;
		}
	};
}
