#include "drinks.h"

ostream& operator<<(ostream& out, drinks* dri)
{

    out << "[" << dri->name << "($" << dri->price << "),ʣ��" << dri->num<<"]";
    return out;
    // TODO: �ڴ˴����� return ���
}
