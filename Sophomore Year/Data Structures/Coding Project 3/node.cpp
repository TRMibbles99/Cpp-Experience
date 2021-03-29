// node.cpp

//default constructor
Node::Node()
{
    C = '\0';
    freq = 0;
    leftPtr = NULL;
    rightPtr = NULL;
}

// constructor
Node::Node(char c, int f)
{
    C = c;
    freq = f;
    leftPtr = NULL;
    rightPtr = NULL;
}

// full node constructor
Node::Node(char c, int f, Node& left, Node& right)
{
    C = c;
    freq = f;
    leftPtr = &left;
    rightPtr = &right;
}

//copy constructor
Node::Node(const Node& nd)
{
    C = nd.C;
    freq = nd.freq;
    leftPtr = nd.leftPtr;
    rightPtr = nd.rightPtr;
}

// overload less than operator
bool Node::operator<(const Node& n)
{
    if (freq < n.freq)
        return true;
    else
        return false;
}

// overload greater than operator
bool Node::operator>(const Node& n)
{
    if (freq > n.freq)
        return true;
    else
        return false;
}

// toString
std::string Node::toString() const
{
    std::stringstream ss;

    if (freq == 0)
    {
        ss << "[ : ]";
    }
    else
    {
        ss << "[" << C << ":" << freq << "]";
    }
    return ss.str();
}

// overload << operator
std::ostream& operator<<(std::ostream& stream, const Node& n)
{
    stream << n.toString();
    return stream;
}
