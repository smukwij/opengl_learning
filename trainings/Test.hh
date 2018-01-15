#include <map>
#include <iostream>


enum class DataId
{
    UNKNOWN,
    FIRST_TYPE,
    SECOND_TYPE
};



template <enum DataId>
class DataType
{
    public:
        static DataId id(){ return DataId::UNKNOWN;}
};


template<>
class DataType <DataId::FIRST_TYPE>
{
    public:
        DataType() = default;
        ~DataType() = default;
        static DataId id(){ return DataId::FIRST_TYPE;}
};

template<>
class DataType <DataId::SECOND_TYPE>
{
    public:

        static DataId id(){ return DataId::SECOND_TYPE;}
};


class Parrent
{
    public:
        Parrent() = default;
        ~Parrent() = default;

        virtual void call() const =0;
};


class ChildA : public Parrent
{
    public:
        ChildA() = default;
        ~ChildA() = default;

        void call() const override final
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
};

class ChildB : public Parrent
{
    public:
        ChildB() = default;
        ~ChildB() = default;

        void call() const override final
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
};



class Test
{
    public:
        Test()
        {
            _objects.insert(std::pair<DataId, Parrent*>(DataId::FIRST_TYPE, new ChildA()));
            _objects.insert(std::pair<DataId, Parrent*>(DataId::SECOND_TYPE, new ChildB()));
        }
        ~Test() = default;

        template<class DataType>
        void call()
        {
            std::map<DataId, Parrent*>::const_iterator cit = _objects.find(DataType::id());
            if(_objects.end() != cit)
            {
                cit->second->call();
            }
        }

    private:
        std::map<DataId, Parrent*> _objects;

};
