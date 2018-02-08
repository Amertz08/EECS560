#ifndef EECS560_BUCKET_HPP
#define EECS560_BUCKET_HPP


class Bucket {
private:
    int _value;

public:
    /**
     * Sets _value to -2. Value of -2 means empty and never inserted.
     * Value of -1 means empty but has been inserted
     */
    Bucket();

    /**
     * Deconstructor
     */
    ~Bucket();

    /**
     * Get value from bucket
     * @return
     */
    int getVal();

    /**
     * Set value in bucket
     * @param val : value to set
     */
    void setVal(int val);

    /**
     * Remove value from bucket
     */
    void remove();

    /**
     * Checks if bucket is empty
     * @return true if empty false if not
     */
    bool empty();

    /**
     * Checks if bucket has ever been set
     * @return true if value has been set. false if not
     */
    bool beenSet();
};


#endif //EECS560_BUCKET_HPP
