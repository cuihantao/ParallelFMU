#include "fmi/ValueCollection.hpp"

namespace FMI
{

    // Use of constructor delegation.
    ValueCollection::ValueCollection()
            : ValueCollection(0ul, 0ul, 0ul, 0ul)
    {
    }

    // Use of constructor delegation.
    ValueCollection::ValueCollection(const ValueCollection & in)
            : ValueCollection(in._realValues, in._intValues, in._boolValues, in._stringValues)
    {
    }

    ValueCollection::ValueCollection(size_type realSize, size_type intSize, size_type boolSize, size_type stringSize)
            : _realValues(vector<real_type>(realSize)),
              _intValues(vector<int_type>(intSize)),
              _boolValues(vector<bool_type>(boolSize)),
              _stringValues(vector<string_type>(stringSize))
    {
    }

    ValueCollection::ValueCollection(const vector<real_type> & real, const vector<int_type> & integer, const vector<bool_type> & boolean,
                                     const vector<string_type> & str)
            : _realValues(real),
              _intValues(integer),
              _boolValues(boolean),
              _stringValues(str)
    {
    }

    template<>
    vector<real_type>& ValueCollection::getValues<real_type>()
    {
        return _realValues;
    }

    template<>
    vector<int_type>& ValueCollection::getValues<int_type>()
    {
        return _intValues;
    }

    template<>
    vector<bool_type>& ValueCollection::getValues<bool_type>()
    {
        return _boolValues;
    }

    template<>
    vector<string_type>& ValueCollection::getValues<string_type>()
    {
        return _stringValues;
    }

    template<>
    const vector<string_type>& ValueCollection::getValues<string_type>() const
    {
        return _stringValues;
    }

    template<>
    const vector<bool_type>& ValueCollection::getValues<bool_type>() const
    {
        return _boolValues;
    }

    template<>
    const vector<int_type>& ValueCollection::getValues<int_type>() const
    {
        return _intValues;
    }

    template<>
    const vector<real_type>& ValueCollection::getValues<real_type>() const
    {
        return _realValues;
    }

    void ValueCollection::assign(const ValueCollection & in)
    {
        assignInternal<real_type>(in);
        assignInternal<int_type>(in);
        assignInternal<bool_type>(in);
        assignInternal<string_type>(in);
    }

    ValueCollection & ValueCollection::operator=(const ValueCollection & in)
    {
        this->_realValues = in._realValues;
        this->_boolValues = in._boolValues;
        this->_intValues = in._intValues;
        this->_stringValues = in._stringValues;
        return *this;
    }

    size_t ValueCollection::size() const
    {
        return _boolValues.size() + _intValues.size() + _stringValues.size() + _realValues.size();
    }

    bool_type ValueCollection::empty() const
    {
        return _boolValues.empty() && _intValues.empty() && _stringValues.empty() && _realValues.empty();
    }

    ostream & operator<<(ostream & out, const ValueCollection & in)
    {
        out << "[Real:|";
        for (auto val : in.getValues<real_type>())
        {
            out << "" << val << "|";
        }
        out << ",Int:|";
        for (auto val : in.getValues<int_type>())
        {
            out << "" << val << "|";
        }
        out << ",Bool:|";
        for (auto val : in.getValues<bool_type>())
        {
            out << "" << ((val == 0) ? false : true) << "|";
        }
        out << ",String:|";
        for (auto val : in.getValues<string_type>())
        {
            out << "" << val << "|";
        }
        out << "]";
        return out;
    }

} /* namespace FMI */

string_type to_string(const FMI::ValueCollection & in)
{
    std::stringstream res;
    res << in;
    return res.str();
}
