/*CMyString类的赋值运算符函数*/
CMyString & CMyString::operator =(const CMyString & optr){
	if(this == &optr)
		return *this;

	delete []m_pData;//清除当前实例指向的字符串数组
	m_pData = NULL;

	m_pData = new char[strlen(optr.m_pData) + 1];//末尾'\0'也需要分配空间
	strcpy(m_pData, optr.m_pData);

	return *this;
}

CMyString & operator =(const CMyString & str){
	if(this != &str){
		CMyString temp(str);

		char *tempS = temp.m_pData;
		temp.m_pData = m_pData;
		m_pData = tempS;
	}
	
	return *this;
}