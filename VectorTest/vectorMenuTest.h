// #pragma Once
#ifndef VECTORMENUTEST_H
#define VECTORMENUTEST_H

template <typename T> class Vector {
public:
  Vector() {
    // allocate 2 elements
    ReAllocate(2);
  }

  ~Vector() { delete[] m_Data; }

    // reduce the size of the vector
  void PopBack() {
    if (m_Size > 0) {
      m_Size--;
      m_Data[m_Size].~T();
    }
  }

    //  clear the vector
  void Clear() {
    for (size_t i = 0; i < m_Size; ++i)
      m_Data[i].~T();
    m_Size = 0;
  }

  void PushBack(const T &value) {
    // check size and increase capacity if needed by a half
    if (m_Size >= m_Capacity) {
      ReAllocate(m_Capacity + m_Capacity / 2);
    }
    m_Data[m_Size] = value;
    m_Size++;
  }

  void PushBack(T &&value) {
    // check size and increase capacity if needed by a half
    if (m_Size >= m_Capacity) {
      ReAllocate(m_Capacity + m_Capacity / 2);
    }
    m_Data[m_Size] = std::move(value);
    m_Size++;
  }

  template <typename... Args> 
  T &EmplaceBack(Args &&... args) {
    if (m_Size >= m_Capacity) {
      ReAllocate(m_Capacity + m_Capacity / 2);
    }
    m_Data[m_Size] = T(std::forward<Args>(args)...);
    return m_Data[m_Size++];
    // m_Size++;
  }

  // return data in the vector
  const T &operator[](size_t index) const { return m_Data[index]; }

  // use a non-const version to modify data inside the vector
  T &operator[](size_t index) { return m_Data[index]; }

  size_t Size() const { return m_Size; }

private:
  T *m_Data = nullptr;

  // capture the number of elements inside the Vector
  size_t m_Size = 0;
  // capture how much memory is allocated
  size_t m_Capacity = 0;

  void ReAllocate(size_t newCapacity) {
    // Step 1: allocate a new block of memory
    // Step 2: move the old elements into the new block
    // Step 3: delete those elements
    T *newBlock = new T[newCapacity];

    // check if Capacity is going down
    if (newCapacity < m_Size)
      m_Size = newCapacity;

    for (size_t i = 0; i < m_Size; ++i)
      newBlock[i] = std::move(m_Data[i]);

    delete[] m_Data;
    m_Data = newBlock;
    m_Capacity = newCapacity;
  }
};

#endif // VECTORMENUTEST_H