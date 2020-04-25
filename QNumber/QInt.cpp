﻿#include "QInt.h"

/**
 *	Constructor QInt - Hàm khởi tạo mặc định QInt = 0
 *	@param	 none
 *	@return	 none
 */
QInt::QInt()
{
	for (int i = 0; i < TOTAL_BLOCK; i++)		//Khởi tạo mỗi block bằng 0
	{
		this->data[i] = 0;
	}
}

/**
 *	Constructor QInt - Hàm khởi tạo QInt từ chuỗi số truyền vào với cơ số thích hợp
 *	@param	 const string&		Chuỗi số cần chuyển thành QInt
 *	@param	 const int			Hệ cơ số của chuỗi
 *	@return	 none
 */
QInt::QInt(const string& src, const int base)
{
	switch (base)
	{
	case 2:
		*this = QInt::convertBinToQInt(src);
		break;
	case 10:
		*this = QInt::convertDecToQInt(src);
		break;
	case 16:
		*this = QInt::convertHexToQInt(src);
		break;
	}

}

QInt::~QInt()
{
}

void QInt::scanQInt(const string& src, const int base)
{
	switch (base)
	{
	case 2:
		*this = QInt::convertBinToQInt(src);
		break;
	case 10:
		*this = QInt::convertDecToQInt(src);
		break;
	case 16:
		*this = QInt::convertHexToQInt(src);
		break;
	}
}

void QInt::printQInt(const int base)
{
	switch (base)
	{
	case 2:
		cout << QInt::convertQIntToBin(*this) << endl;
		break;
	case 10:
		cout << QInt::convertQIntToDec(*this) << endl;
		break;
	case 16:
		cout << QInt::convertQIntToHex(*this) << endl;
		break;
	}
}

string QInt::convertQIntToBin(QInt src)
{
	string result = "";

	for (int i = 0; i < BIT_IN_QINT; i++)
	{
		result = (char)(BUtils::getBit(src.data, i) + '0') + result;
	}

	while (result[0] == '0' && result.size() > 1)
	{
		result.erase(0, 1);
	}

	return result;
}

string QInt::convertQIntToDec(QInt src)
{
	string srcBin;
	string result = "0";

	if (src.isNegative())
	{
		src = QInt::inverseTwoComplement(src);
	}

	for (int i = 0; i < BIT_IN_QINT; i++)
	{
		if (BUtils::getBit(src.data, i) == 1)
		{
			result = SUtils::addTwoPositiveIntegerString(result, SUtils::powerOfTwo(i));
		}
	}

	return result;
}

string QInt::convertQIntToHex(QInt src)
{
	return SUtils::convertBinToHex(QInt::convertQIntToBin(src));
}

QInt QInt::convertBinToQInt(const string& src)
{
	QInt result;

	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] == '1')
		{
			BUtils::setBit(result.data, src.size() - i - 1);
		}
	}

	return result;
}

QInt QInt::convertDecToQInt(const string& src)
{
	return QInt::convertBinToQInt(SUtils::convertDecToBin(src));
}

QInt QInt::convertHexToQInt(const string& src)
{
	return QInt::convertBinToQInt(SUtils::convertHexToBin(src));
}

bool QInt::isNegative()
{
	return BUtils::getBit(this->data, BIT_IN_QINT - 1);
}

bool QInt::equalZero()
{
	for (int i = 0; i < TOTAL_BLOCK; i++)
	{
		if (this->data[i] != 0)
		{
			return false;
		}
	}

	return true;
}

QInt QInt::convertToTwoComplement(QInt src)
{
	return ~src + QInt("1", 10);
}

QInt QInt::inverseTwoComplement(QInt src)
{
	return ~(src - QInt("1", 10));
}

QInt QInt::operator+(const QInt& other)
{
	return QInt();
}

QInt QInt::operator-(const QInt& other)
{
	return QInt();
}

QInt QInt::operator*(const QInt& other)
{
	return QInt();
}

QInt QInt::operator/(const QInt& other)
{
	return QInt();
}

bool QInt::operator>(const QInt& other)
{
	return false;
}

bool QInt::operator<(const QInt& other)
{
	return false;
}

bool QInt::operator==(const QInt& other)
{
	return false;
}

bool QInt::operator!=(const QInt& other)
{
	return false;
}

bool QInt::operator>=(const QInt& other)
{
	return false;
}

bool QInt::operator<=(const QInt& other)
{
	return false;
}

QInt& QInt::operator=(const QInt& other)
{
	if (other.data == this->data)
	{
		return *this;
	}

	for (int i = 0; i < TOTAL_BLOCK; i++)
	{
		this->data[i] = other.data[i];
	}

	return *this;
}

QInt QInt::operator&(const QInt& other)
{
	return QInt(); 
	// em nho chu y minh dang o branch nao nha..ne cai master nay ra nha em
	//do em chua cap nhat nen hoi khac anh xiu
	//gio anh test commit ne..mai mot em cu lam tuong tu nhu vay
	//cach 1 em vao day
	//cach 2 em click phai vao file thay doi co dau tick do a em..neu co nhieu file thay doi em
	//tick cai nao cung duoc
}

QInt QInt::operator|(const QInt& other)
{
	return QInt();
}

QInt QInt::operator^(const QInt& other)
{
	return QInt();
}

QInt QInt::operator~() const
{
	return QInt();
}

QInt QInt::operator>>(const int& offset)
{
	return QInt();
}

QInt QInt::operator<<(const int& offset)
{
	return QInt();
}

QInt& QInt::rol()
{
	// TODO: insert return statement here
	return *this;
}

QInt& QInt::ror()
{
	// TODO: insert return statement here
	return *this;
}