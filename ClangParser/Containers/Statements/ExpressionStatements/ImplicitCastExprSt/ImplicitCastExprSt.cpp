#include "ImplicitCastExprSt.hpp"  

ImplicitCastExprSt::ImplicitCastExprSt()
{

}

ImplicitCastExprSt::~ImplicitCastExprSt()
{

}

string ImplicitCastExprSt::getRefType()
{
	return this->RefType;
}

void ImplicitCastExprSt::setRefType(string reftype)
{
	this->RefType = reftype;
}

string ImplicitCastExprSt::ToString(string format) 
{
	string buffer = "";
	
	if(format == "Json")
	{
		pt::ptree root = GetInitialpTree();
		root.put("Type", this->getType());
		root.put("Reference Type", RefType);
		buffer = JsonUtility::GetJsonString(root);
	}
	else
	{
		buffer = "[ImplicitCastExpr] ";
	}
	
	return buffer;
}

void ImplicitCastExprSt::FromString(string format,string buffer) 
{
	if(format=="Json")
	{
		pt::ptree root = JsonUtility::GetJsonObject(buffer);
		this->setText(root.get<string>("Text", "Undefined Text"));
		this->setType(root.get<string>("Type", "Undefined Type"));
		this->RefType = root.get<string>("Reference Type", "Undefined Reference Type");
	}
}