#pragma once
class DOT
{private:
	float x_start,y_start,x_end,y_end;
public:
	DOT();//конструктор по умолчанию; 
	void set_data(float x_value_start, float y_value_start, float x_value_end, float y_value_end);

	float Get_x_start() const;
	float Get_y_start() const;
	float Get_x_end() const;
	float Get_y_end() const;
	//
	float Modul_vector();
	float& operator*(const DOT A);
	DOT& operator+(const DOT A);
	DOT& operator-(const DOT A);
	void coleniarn(DOT A, DOT B);
	bool zero_vector(DOT A, DOT B);
};

