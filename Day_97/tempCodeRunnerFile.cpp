
    }
    // push new element at first
    void push_front(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            this->head = newNode;
            this->size++;
        }
        else
        {
            Node *temp = newNode;
            temp->setNextNodeAddress(this->head);
            this->head->setNextNodeAddress(temp);
        }
    }
