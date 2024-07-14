#include "Film.h"

Film::Film():
    chaptersNumber(0), chaptersDurations(nullptr)
{}

Film::Film(std::string name, std::string pathname):
    Video(name, pathname, duration),
    chaptersNumber(0), chaptersDurations(nullptr)
{}

Film::Film(std::string name, std::string pathname,
           int duration, int chaptersNumber, int* chaptersDurations):
    Video(name, pathname, duration)
  //chaptersNumber(chaptersNumber), chaptersDurations(chaptersDurations)
{
    this->setChaptersDurations(chaptersDurations,chaptersNumber);
}

Film::Film(const Film& from) : Video(from)
{
    chaptersNumber = from.chaptersNumber;
    if (from.chaptersDurations)
    {
        int * copyArray = new int[chaptersNumber];
        for (int i = 0; i < from.chaptersNumber; i++)
        {
            copyArray[i] = from.chaptersDurations[i];
        }
        chaptersDurations = copyArray;
    }
    else
        chaptersDurations = nullptr;
}

Film& Film::operator=(const Film& from)
{
    Video::operator=(from);
    chaptersNumber = from.chaptersNumber;
    if (chaptersDurations && from.chaptersDurations)
        *chaptersDurations = *(from.chaptersDurations);
    else
    {
        delete chaptersDurations;
        if (from.chaptersDurations)
        {
            int * copyArray = new int[chaptersNumber];
            for (int i = 0; i < from.chaptersNumber; i++)
            {
                copyArray[i] = from.chaptersDurations[i];
            }
            chaptersDurations = copyArray;
        }
        else
            chaptersDurations = nullptr;
    }
    return *this;
}

void Film::setChaptersDurations(const int* chaptersDurations,const int chaptersNumber)
{
    int * copyArray = new int[chaptersNumber];
    for (int i = 0; i<chaptersNumber; i++)
    {
        copyArray[i] = chaptersDurations[i];
    }
    delete this->chaptersDurations;
    this->chaptersDurations = copyArray;
    this->chaptersNumber = chaptersNumber;
}


// Normally, const int* const Film::getChaptersDurations() const
// but "const int*" won't allow the altering of the pointed value but still enables its deletion
// "int * const" won't allow the altering of the pointer's value but isn't useful
//const int* const Film::getChaptersDurations() const
int* Film::getChaptersDurations() const
{
    int * copyArray = new int[this->chaptersNumber];
    for (int i = 0; i < this->chaptersNumber; i++)
    {
        copyArray[i] = chaptersDurations[i];
    }

    return copyArray;
}

int Film::getChaptersNumber() const
{
    return this->chaptersNumber;
}

void Film::describe(std::ostream& stream) const
{
    Video::describe(stream);
    if (this->chaptersDurations)
    {
        stream << "Chapters description..." << std::endl;
        for (int i=0; i < this->chaptersNumber; i++)
        {
            stream << "Chapter " << i+1 << "'s duration is " << this->chaptersDurations[i]
                      << std::endl;
        }
    }
    else
    {
        stream << "Undefined chapters' durations" << std::endl;
    }
}

Film::~Film()
{
    delete chaptersDurations;
}


