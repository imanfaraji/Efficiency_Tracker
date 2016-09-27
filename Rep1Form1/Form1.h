/************************************************************
Project Name: Efficiency Tracker

Project Description:

* Efficiency tracker allows to track your efficient working 
* hour during the day. It tracks of the useful and non-useful
* hours during a day. It also records the daily statistics into
* an excel.

* This is the main window and includes four stopwatch timers
* 1. Efficient
* 2. Emmergency
* 3. Rest
* 4. Wasted 

Efficient Stopwatch:
* Tracks the actual time that was spent on just working/studying
Emmergency Stopwatch:
* Tracks the time that was spent on emergency events. E.g., 
* Supervisor calls you to his office or going to the washroom!!
Rest Stopwatch:
* Tracks the time that was spent on resting. E.g., Eating lunch
Waste Stopwatch:
* Tracks the time that is actually wasted. Basically the time that
* you could have avoided it and it was't a part of your rest time.

* When the program is finished the efficiency statistics will
* be recorded in an Excel file.

Developped by: Iman Faraji
************************************************************/


#include "Form2.h"
#include <time.h>
#include <string>
#include <math.h>
#include <direct.h>
#include "classes.h"

#pragma once


namespace Rep1Form1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
		int start_h, start_m, start_s, stop_h, stop_m, stop_s, start_year, start_month, start_day;
		static long double *eff_perc = new long double;

		static int *t_d = new int[3];
		static int *t_a = new int[3];

		static int Sec = 0;
		static int Min = 0;
		static int Hr = 0;
		String^ Second;
		String^ Minute;
		String^ Hour;

		static PrintFile *PF = new PrintFile();

		static System::DateTime^ start_now;
		static System::DateTime^ stop_now;

		static bool is_file_open = false;

		String^ Second_st;
		String^ Minute_st;
		String^ Hour_st;

		//IMAN ADDED: define and intialize stopwatch for Rest time
		static int Sec_r = 0;
		static int Min_r = 0;
		static int Hr_r = 0;
		String^ Second_r;
		String^ Minute_r;
		String^ Hour_r;


		//IMAN ADDED: define and intialize stopwatch for Emergency time
		static int Sec_e = 0;
		static int Min_e = 0;
		static int Hr_e = 0;
		String^ Second_e;
		String^ Minute_e;
		String^ Hour_e;

		//IMAN ADDED: define and intialize stopwatch for Wasted time
		static int Sec_W = 0;
		static int Min_W = 0;
		static int Hr_W = 0;
		String^ Second_W;
		String^ Minute_W;
		String^ Hour_W;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  lblstart;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  lblstop;


	private: System::Windows::Forms::Button^  plus_emrg;
	private: System::Windows::Forms::Button^  minus_emrg;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8_minus;

	private: System::Windows::Forms::Button^  button9_plus;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;


	private: 


	private: System::Windows::Forms::Timer^  timer3;

	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Exit;
	private: System::Windows::Forms::Label^  lblStopwatch;

	private: System::Windows::Forms::Button^  BtnHello;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->lblStopwatch = (gcnew System::Windows::Forms::Label());
			this->BtnHello = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->lblstart = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->lblstop = (gcnew System::Windows::Forms::Label());
			this->plus_emrg = (gcnew System::Windows::Forms::Button());
			this->minus_emrg = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8_minus = (gcnew System::Windows::Forms::Button());
			this->button9_plus = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// Exit
			// 
			this->Exit->Location = System::Drawing::Point(12, 12);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(82, 23);
			this->Exit->TabIndex = 0;
			this->Exit->Text = L"E&xit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &Form1::Exit_Click);
			// 
			// lblStopwatch
			// 
			this->lblStopwatch->AutoSize = true;
			this->lblStopwatch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblStopwatch->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblStopwatch->Location = System::Drawing::Point(4, 57);
			this->lblStopwatch->Name = L"lblStopwatch";
			this->lblStopwatch->Size = System::Drawing::Size(212, 55);
			this->lblStopwatch->TabIndex = 1;
			this->lblStopwatch->Text = L"00:00:00";
			this->lblStopwatch->Click += gcnew System::EventHandler(this, &Form1::lblHello_Click);
			// 
			// BtnHello
			// 
			this->BtnHello->Location = System::Drawing::Point(112, 12);
			this->BtnHello->Name = L"BtnHello";
			this->BtnHello->Size = System::Drawing::Size(95, 23);
			this->BtnHello->TabIndex = 2;
			this->BtnHello->Text = L"Start";
			this->BtnHello->UseVisualStyleBackColor = true;
			this->BtnHello->Click += gcnew System::EventHandler(this, &Form1::BtnHello_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(221, 100);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Stop-Waste";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(220, 57);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Stop-Rest";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(220, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Stop-Emergency";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(346, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"00:00:00";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label2->Location = System::Drawing::Point(346, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 33);
			this->label2->TabIndex = 6;
			this->label2->Text = L"00:00:00";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(346, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 33);
			this->label3->TabIndex = 7;
			this->label3->Text = L"00:00:00";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Interval = 1000;
			this->timer4->Tick += gcnew System::EventHandler(this, &Form1::timer4_Tick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(226, 142);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(93, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Finish";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// lblstart
			// 
			this->lblstart->AutoSize = true;
			this->lblstart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblstart->Location = System::Drawing::Point(33, 44);
			this->lblstart->Name = L"lblstart";
			this->lblstart->Size = System::Drawing::Size(63, 13);
			this->lblstart->TabIndex = 9;
			this->lblstart->Text = L"Stated at:";
			this->lblstart->Click += gcnew System::EventHandler(this, &Form1::lblstart_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(3, 142);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(209, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Resume";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// lblstop
			// 
			this->lblstop->AutoSize = true;
			this->lblstop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblstop->Location = System::Drawing::Point(33, 114);
			this->lblstop->Name = L"lblstop";
			this->lblstop->Size = System::Drawing::Size(73, 13);
			this->lblstop->TabIndex = 11;
			this->lblstop->Text = L"Finished at:";
			this->lblstop->Click += gcnew System::EventHandler(this, &Form1::lblstop_Click);
			// 
			// plus_emrg
			// 
			this->plus_emrg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->plus_emrg->ForeColor = System::Drawing::Color::Black;
			this->plus_emrg->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->plus_emrg->Location = System::Drawing::Point(472, 12);
			this->plus_emrg->Name = L"plus_emrg";
			this->plus_emrg->Size = System::Drawing::Size(23, 23);
			this->plus_emrg->TabIndex = 13;
			this->plus_emrg->Text = L"+";
			this->plus_emrg->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->plus_emrg->UseVisualStyleBackColor = true;
			this->plus_emrg->Click += gcnew System::EventHandler(this, &Form1::plus_emrg_Click);
			// 
			// minus_emrg
			// 
			this->minus_emrg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->minus_emrg->ForeColor = System::Drawing::Color::Black;
			this->minus_emrg->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->minus_emrg->Location = System::Drawing::Point(320, 12);
			this->minus_emrg->Name = L"minus_emrg";
			this->minus_emrg->Size = System::Drawing::Size(23, 23);
			this->minus_emrg->TabIndex = 14;
			this->minus_emrg->Text = L"-";
			this->minus_emrg->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->minus_emrg->UseVisualStyleBackColor = true;
			this->minus_emrg->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(348, 138);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(33, 20);
			this->numericUpDown1->TabIndex = 15;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(398, 138);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(33, 20);
			this->numericUpDown2->TabIndex = 16;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(445, 138);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(33, 20);
			this->numericUpDown3->TabIndex = 17;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button6->Location = System::Drawing::Point(471, 56);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(23, 23);
			this->button6->TabIndex = 18;
			this->button6->Text = L"+";
			this->button6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::Black;
			this->button7->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button7->Location = System::Drawing::Point(320, 57);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(23, 23);
			this->button7->TabIndex = 19;
			this->button7->Text = L"-";
			this->button7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click_1);
			// 
			// button8_minus
			// 
			this->button8_minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8_minus->ForeColor = System::Drawing::Color::Black;
			this->button8_minus->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button8_minus->Location = System::Drawing::Point(319, 101);
			this->button8_minus->Name = L"button8_minus";
			this->button8_minus->Size = System::Drawing::Size(23, 23);
			this->button8_minus->TabIndex = 20;
			this->button8_minus->Text = L"-";
			this->button8_minus->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button8_minus->UseVisualStyleBackColor = true;
			this->button8_minus->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9_plus
			// 
			this->button9_plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9_plus->ForeColor = System::Drawing::Color::Black;
			this->button9_plus->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button9_plus->Location = System::Drawing::Point(472, 100);
			this->button9_plus->Name = L"button9_plus";
			this->button9_plus->Size = System::Drawing::Size(23, 23);
			this->button9_plus->TabIndex = 21;
			this->button9_plus->Text = L"+";
			this->button9_plus->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button9_plus->UseVisualStyleBackColor = true;
			this->button9_plus->Click += gcnew System::EventHandler(this, &Form1::button9_plus_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(385, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(12, 16);
			this->label4->TabIndex = 22;
			this->label4->Text = L":";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(431, 140);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(12, 16);
			this->label5->TabIndex = 23;
			this->label5->Text = L":";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 171);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button9_plus);
			this->Controls->Add(this->button8_minus);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->minus_emrg);
			this->Controls->Add(this->plus_emrg);
			this->Controls->Add(this->lblstop);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->lblstart);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->BtnHello);
			this->Controls->Add(this->lblStopwatch);
			this->Controls->Add(this->Exit);
			this->Name = L"Form1";
			this->Text = L"Efficiency Tracker";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form2^ f2 = gcnew Form2();
				 f2->ShowDialog();
				 
				 //Application::Exit();
			 }
	private: System::Void BtnHello_Click(System::Object^  sender, System::EventArgs^  e) {
			  start_now = System::DateTime::Now;
			  
			  //IMAN ADDED: WHAT NEES TO BE DONE WHEN THE PROGRAM STARTS

			  start_h = start_now->Hour;
			  start_m = start_now->Minute;
			  start_s = start_now->Second;

			  start_year = start_now->Year;
			  start_month = start_now->Month;
			  start_day = start_now->Day;


			  Hour_st = Convert::ToString(start_h);
			  Minute_st = Convert::ToString(start_m);
			  Second_st = Convert::ToString(start_s);

			  //IMAN ADDED: SHOW AT WHAT TIME THIS PROGRAM IS STARTED

			 lblstart->Text = "Started at: " + (start_now->Hour < 10 ? "0" + Hour_st: Hour_st) + ":" + (start_now->Minute < 10 ? "0" + Minute_st: Minute_st) + ":" + (start_now->Second < 10 ? "0" + Second_st: Second_st);
 
			 //IMAN ADDED: ENABLE THE MAIN COUNTER
			 timer1->Enabled = true;
			 timer2->Enabled = false;
			 timer3->Enabled = false;
			 timer4->Enabled = false;

			 }

			 //MAIN TIMER/STOPWATCH IS DEFINED HERE
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) { 

				 Sec++;
				 if (Sec == 60)
				 {
					Sec = 0;
					Min++;
					if (Min == 60) 
					{
						Hr++;
						Min = 0;
					}

				 }

				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);

				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);

			 }
private: System::Void lblHello_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {

			 
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 timer1->Enabled = false;
			 timer2->Enabled = true;
			 timer3->Enabled = false;
			 timer4->Enabled = false;
		 
		 }


		 //IMAN ADDED: TIMER/STOPWATCH TO TRACK WASTED TIME IS DEFINED HERE
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

		 		 Sec_W++;
				 if (Sec_W == 60)
				 {
					Sec_W = 0;
					Min_W++;
					if (Min_W == 60) 
					{
						Hr_W++;
						Min_W = 0;
					}

				 }

				 Second_W = Convert::ToString(Sec_W); 
				 Minute_W = Convert::ToString(Min_W);
				 Hour_W = Convert::ToString(Hr_W);

				 label1->Text =(Hr_W < 10 ? "0" + Hour_W: Hour_W) + ":" + (Min_W < 10 ? "0" + Minute_W: Minute_W) + ":" + (Sec_W < 10 ? "0" + Second_W: Second_W);
		 
}

//IMAN ADDED: TIMER/STOPWATCH TO TRACK REST TIME IS DEFINED HERE
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {

		 		 Sec_r++;
				 if (Sec_r == 60)
				 {
					Sec_r = 0;
					Min_r++;
					if (Min_r == 60) 
					{
						Hr_r++;
						Min_r = 0;
					}

				 }

				 Second_r = Convert::ToString(Sec_r); 
				 Minute_r = Convert::ToString(Min_r);
				 Hour_r = Convert::ToString(Hr_r);

				 label2->Text =(Hr_r < 10 ? "0" + Hour_r: Hour_W) + ":" + (Min_r < 10 ? "0" + Minute_r: Minute_r) + ":" + (Sec_r < 10 ? "0" + Second_r: Second_r);

		 }
		 //IMAN ADDED: TIMER/STOPWATCH TO TRACK EMERGENCY TIME IS DEFINED HERE
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
			 
		 		 Sec_e++;
				 if (Sec_e == 60)
				 {
					Sec_e = 0;
					Min_e++;
					if (Min_e == 60) 
					{
						Hr_e++;
						Min_e = 0;
					}

				 }

				 Second_e = Convert::ToString(Sec_e); 
				 Minute_e = Convert::ToString(Min_e);
				 Hour_e = Convert::ToString(Hr_e);

				 label3->Text =(Hr_e < 10 ? "0" + Hour_e: Hour_e) + ":" + (Min_e < 10 ? "0" + Minute_e: Minute_e) + ":" + (Sec_e < 10 ? "0" + Second_e: Second_e);

		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = false;
			 timer2->Enabled = false;
			 timer3->Enabled = true;
			 timer4->Enabled = false;

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = false;
			 timer2->Enabled = false;
			 timer3->Enabled = false;
			 timer4->Enabled = true;

		 }

		 //IMAN ADDED: FINISH BUTTON IS DEFINED HERE
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

			 timer1->Enabled = false;
			 timer2->Enabled = false;
			 timer3->Enabled = false;
			 timer4->Enabled = false;

			 stop_now = System::DateTime::Now;

			 stop_h = stop_now->Hour;
			 stop_m = stop_now->Minute;
			 stop_s = stop_now->Second;
			 Hour_st = Convert::ToString(stop_h);
			 Minute_st = Convert::ToString(stop_m);
			 Second_st = Convert::ToString(stop_s);

			lblstop->Text = "Finished at: " + (stop_now->Hour < 10 ? "0" + Hour_st: Hour_st) + ":" + (stop_now->Minute < 10 ? "0" + Minute_st: Minute_st) + ":" + (stop_now->Second < 10 ? "0" + Second_st: Second_st);
			 
			is_file_open = PF->OPEN(); //IMAN ADDED: OPEN THE EXCEL FILE
			if (is_file_open == false)
			{
				_mkdir("c:/EFFICIENCY_TRACKER");
				//std::ofstream file("newfile.txt");
				PF->OPEN();
				PF->WRITE("DATE,START,STOP,TOTAL,EFFICIENT,EFF%,,EMERGENCY,REST,WASTE,EFF+EMR%,EFF+REST%,EFF+EMR+REST%");
			}
			PF->WRITE("\n" + std::to_string((long long) start_year) + "-" + std::to_string((long long) start_month) + "-" +std::to_string((long long) start_day) + ",");// Start Date
			PF->WRITE(std::to_string((long long) start_h) + ":" + std::to_string((long long) start_m) + ":" +std::to_string((long long) start_s) + ",");//Start Time
			PF->WRITE(std::to_string((long long) stop_h) + ":" + std::to_string((long long) stop_m) + ":" +std::to_string((long long) stop_s) + ",");//Stop Time

			time_diff(start_h,start_m,start_s,stop_h,stop_m,stop_s,t_d);
			PF->WRITE(std::to_string((long long) t_d[2]) + ":" + std::to_string((long long) t_d[1]) + ":" +std::to_string((long long) t_d[0]) + ",");//Total Time

			PF->WRITE(std::to_string((long long) Hr) + ":" + std::to_string((long long) Min) + ":" +std::to_string((long long) Sec) + ",");//Efficient Time

			eff_perc[0] = perc(t_d[2], t_d[1], t_d[0], Hr, Min, Sec);
			PF->WRITE(std::to_string(ceil(eff_perc[0])) + "%" +",");//IMAN ADDED: REPORT Efficient Time %
			PF->WRITE(",");//SKIP one Column

			PF->WRITE(std::to_string((long long) Hr_e) + ":" + std::to_string((long long) Min_e) + ":" +std::to_string((long long) Sec_e) + ",");//Emergency Time
			PF->WRITE(std::to_string((long long) Hr_r) + ":" + std::to_string((long long) Min_r) + ":" +std::to_string((long long) Sec_r) + ",");//Rest Time
			PF->WRITE(std::to_string((long long) Hr_W) + ":" + std::to_string((long long) Min_W) + ":" +std::to_string((long long) Sec_W) + ",");//Waste Time

			time_add(Hr_e,Min_e,Sec_e,Hr,Min,Sec,t_a);
			eff_perc[0] = perc(t_d[2], t_d[1], t_d[0], t_a[2], t_a[1], t_a[0]);
			PF->WRITE(std::to_string(ceil(eff_perc[0])) + "%" +",");//IMAN ADDED: REPORT Efficient + Emergency Time %

			time_add(Hr_r,Min_r,Sec_r,Hr,Min,Sec,t_a);
			eff_perc[0] = perc(t_d[2], t_d[1], t_d[0], t_a[2], t_a[1], t_a[0]);
			PF->WRITE(std::to_string(ceil(eff_perc[0])) + "%" +",");//IMAN ADDED: REPORT Efficient + Rest Time %

			time_add(Hr_e,Min_e,Sec_e,t_a[2],t_a[1],t_a[0],t_a);
			eff_perc[0] = perc(t_d[2], t_d[1], t_d[0], t_a[2], t_a[1], t_a[0]);
			PF->WRITE(std::to_string(ceil(eff_perc[0])) + "%");//IMAN ADDED: REPORT Efficient + Emergency + Rest Time %
						
			PF->CLOSE(); //IMAN ADDED: CLOSE THE EXCEL FILE
		 }
private: System::Void lblstart_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

			 timer1->Enabled = true;
			 timer2->Enabled = false;
			 timer3->Enabled = false;
			 timer4->Enabled = false;


		 }
private: System::Void lblstop_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
public: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

		
		}
		//IMAN ADDEd: Adjust the Emergenccy time
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				 
			 	 Sec_e -= System::Int32(numericUpDown3->Value);
				 if (Sec_e<0)
				 {
					 Sec_e+=60;
					 Min_e--;
				 }
				 Min_e -= System::Int32(numericUpDown2->Value);
				 if (Min_e<0)
				 {
					 Min_e+=60;
					 Hr_e--;
				 }
			 Hr_e -= System::Int32(numericUpDown1->Value);// = 10;
				 Second_e = Convert::ToString(Sec_e); 
				 Minute_e = Convert::ToString(Min_e);
				 Hour_e = Convert::ToString(Hr_e);

				 label3->Text =(Hr_e < 10 ? "0" + Hour_e: Hour_e) + ":" + (Min_e < 10 ? "0" + Minute_e: Minute_e) + ":" + (Sec_e < 10 ? "0" + Second_e: Second_e);

				 Hr += System::Int32(numericUpDown1->Value);
				 Sec += System::Int32(numericUpDown3->Value);
				 if (Sec >= 60)
				 {
					 Sec-=60;
					 Min++;
				 }

				 Min += System::Int32(numericUpDown2->Value);
				 if (Min >= 60)
				 {
					 Min-=60;
					 Hr++;
				 }
				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);
				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);

		 }

public: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
public: System::Void numericUpDown3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
		//IMAN ADDEd: Adjust the Emergenccy time
private: System::Void plus_emrg_Click(System::Object^  sender, System::EventArgs^  e) {

				 Hr_e += System::Int32(numericUpDown1->Value);
				 Sec_e += System::Int32(numericUpDown3->Value);
				 if (Sec_e >= 60)
				 {
					 Sec_e-=60;
					 Min_e++;
				 }
				 
				 Min_e += System::Int32(numericUpDown2->Value);
				 if (Min_e >= 60)
				 {
					 Min_e-=60;
					 Hr_e++;
				 }
				 Second_e = Convert::ToString(Sec_e); 
				 Minute_e = Convert::ToString(Min_e);
				 Hour_e = Convert::ToString(Hr_e);

				 Sec -= System::Int32(numericUpDown3->Value);
				 if (Sec<0)
				 {
					 Sec+=60;
					 Min--;
				 }
				 Min -= System::Int32(numericUpDown2->Value);
				 if (Min<0)
				 {
					 Min+=60;
					 Hr--;
				 }
				 
				 Hr -= System::Int32(numericUpDown1->Value);

				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);
				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);

				 label3->Text =(Hr_e < 10 ? "0" + Hour_e: Hour_e) + ":" + (Min_e < 10 ? "0" + Minute_e: Minute_e) + ":" + (Sec_e < 10 ? "0" + Second_e: Second_e);
				 
		 }


private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		//IMAN Added: INCREASE THE REST TIME USING NumericUPdown number and ADJUST THE EFFICIENT TIME
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 Hr_r += System::Int32(numericUpDown1->Value);
				
				 Sec_r += System::Int32(numericUpDown3->Value);
				 if (Sec_r >= 60)
				 {
					 Sec_r-=60;
					 Min_r++;
				 }
				 
				 Min_r += System::Int32(numericUpDown2->Value);
				 if (Min_r >= 60)
				 {
					 Min_r-=60;
					 Hr_r++;
				 }

				 Second_r = Convert::ToString(Sec_r); 
				 Minute_r = Convert::ToString(Min_r);
				 Hour_r = Convert::ToString(Hr_r);

				 label2->Text =(Hr_r < 10 ? "0" + Hour_r: Hour_W) + ":" + (Min_r < 10 ? "0" + Minute_r: Minute_r) + ":" + (Sec_r < 10 ? "0" + Second_r: Second_r);

				 Sec -= System::Int32(numericUpDown3->Value);
				 if (Sec<0)
				 {
					 Sec+=60;
					 Min--;
				 }
				 Min -= System::Int32(numericUpDown2->Value);
				 if (Min<0)
				 {
					 Min+=60;
					 Hr--;
				 }
				 Hr -= System::Int32(numericUpDown1->Value);
				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);
				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);


		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		 //IMAN Added: REDUCE THE REST TIME USING NumericUPdown number and ADJUST THE EFFICIENT TIME
private: System::Void button7_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 	 
			 	Sec_r -= System::Int32(numericUpDown3->Value);
				 if (Sec_r<0)
				 {
					 Sec_r+=60;
					 Min_r--;
				 }
				 Min_r -= System::Int32(numericUpDown2->Value);
				 if (Min_r<0)
				 {
					 Min_r+=60;
					 Hr_r--;
				 }
			 Hr_r -= System::Int32(numericUpDown1->Value);
				 
				 Second_r = Convert::ToString(Sec_r); 
				 Minute_r = Convert::ToString(Min_r);
				 Hour_r = Convert::ToString(Hr_r);

				 label2->Text =(Hr_r < 10 ? "0" + Hour_r: Hour_W) + ":" + (Min_r < 10 ? "0" + Minute_r: Minute_r) + ":" + (Sec_r < 10 ? "0" + Second_r: Second_r);

				 Hr += System::Int32(numericUpDown1->Value);
				 Sec += System::Int32(numericUpDown3->Value);
				 if (Sec >= 60)
				 {
					 Sec-=60;
					 Min++;
				 }
				 Min += System::Int32(numericUpDown2->Value);
				 if (Min >= 60)
				 {
					 Min-=60;
					 Hr++;
				 }
				 
				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);
				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);


		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 
			 Sec_W -= System::Int32(numericUpDown3->Value);
			 if (Sec_W<0)
			 {
				 Sec_W+=60;
				 Min_W--;
			 }
			 Min_W -= System::Int32(numericUpDown2->Value);
			 if (Min_W<0)
			 {
				 Min_W+=60;
				 Hr_W--;
			 }
			 Hr_W -= System::Int32(numericUpDown1->Value);
			 


			     Second_W = Convert::ToString(Sec_W); 
				 Minute_W = Convert::ToString(Min_W);
				 Hour_W = Convert::ToString(Hr_W);

				 label1->Text =(Hr_W < 10 ? "0" + Hour_W: Hour_W) + ":" + (Min_W < 10 ? "0" + Minute_W: Minute_W) + ":" + (Sec_W < 10 ? "0" + Second_W: Second_W);

				 Hr += System::Int32(numericUpDown1->Value);
				 Sec += System::Int32(numericUpDown3->Value);
				 if (Sec >= 60)
				 {
					 Sec-=60;
					 Min++;
				 }
				 Min += System::Int32(numericUpDown2->Value);
				 if (Min >= 60)
				 {
					 Min-=60;
					 Hr++;
				 }
				 
				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);
				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);

		 }
		 //IMAN ADDED: WASTED TIME ADJUSTMENT
private: System::Void button9_plus_Click(System::Object^  sender, System::EventArgs^  e) {

			  	 Hr_W += System::Int32(numericUpDown1->Value);
				 Sec_W += System::Int32(numericUpDown3->Value);
				 if (Sec_W >= 60)
				 {
					 Sec_W-=60;
					 Min_W++;
				 }
				 Min_W += System::Int32(numericUpDown2->Value);
				 if (Min_W >= 60)
				 {
					 Min_W-=60;
					 Hr_W++;
				 }
				 

			     Second_W = Convert::ToString(Sec_W); 
				 Minute_W = Convert::ToString(Min_W);
				 Hour_W = Convert::ToString(Hr_W);

				 label1->Text =(Hr_W < 10 ? "0" + Hour_W: Hour_W) + ":" + (Min_W < 10 ? "0" + Minute_W: Minute_W) + ":" + (Sec_W < 10 ? "0" + Second_W: Second_W);

				 Sec -= System::Int32(numericUpDown3->Value);
				 if (Sec<0)
				 {
					 Sec+=60;
					 Min--;
				 }
				 Min -= System::Int32(numericUpDown2->Value);
				 if (Min<0)
				 {
					 Min+=60;
					 Hr--;
				 }
				 Hr -= System::Int32(numericUpDown1->Value);
				 Second = Convert::ToString(Sec); 
				 Minute = Convert::ToString(Min);
				 Hour = Convert::ToString(Hr);
				 lblStopwatch->Text =(Hr < 10 ? "0" + Hour: Hour) + ":" + (Min < 10 ? "0" + Minute: Minute) + ":" + (Sec < 10 ? "0" + Second: Second);




		 }
};

}

