#include "__preprocessor__.h"
#include <immintrin.h>
#include <mm_malloc.h>

void no_write_allocate_memcpy(char* dst, const char* source, size_t n)
{
    // Ustal, czy adres docelowy jest wyrównany do 32 bajtów.
    uintptr_t dst_addr = reinterpret_cast<uintptr_t>(dst);
    size_t misalign = dst_addr % 32;
    size_t head = 32 - misalign;

    // Jeśli mamy początkowy fragment do wyrównania, skopiuj go standardowo
    if (0 < head && head <= n)
    {
        std::memcpy(dst, source, head);
        dst += head;
        source += head;
        n -= head;
    }

    // Kopiowanie głównej części – pełnych bloków 32-bajtowych
    size_t chunks = n / 32;
    for (size_t i = 0; i < chunks; i++)
    {
        // Ładujemy 32 bajty z pamięci źródłowej, nie martwiąc się o wyrównanie
        __m256i data = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(source));
        // Strumieniowo zapisujemy dane – wymagana jest wyrównana dest
        _mm256_stream_si256(reinterpret_cast<__m256i*>(dst), data);
        dst += 32;
        source += 32;
    }

    // Opcjonalnie, kopiujemy końcowy fragment, który jest mniejszy niż 32 bajty
    size_t tail = n % 32;
    if (tail > 0) { std::memcpy(dst, source, tail); }

    // Zapewnij, że wszystkie operacje strumieniowe zostaną zakończone
    _mm_sfence();
}
