list = [1, 2, "Vermelho", "Carro", 7]

defmodule Exercise1 do

  def addBeginList(obj, list) do
    [obj | list]
  end

  # Imutabilidade -> copiar a lista inteira
  # Padrão -> adicionar sempre ao início e utilizar `Enum.reverse/1`
  def addEndList(obj, list) do
    list ++ [obj]
  end

  def printList(list) do
    IO.inspect(list)
  end

  def printFirst(list) do
    IO.inspect(hd list)
  end

  def printLengthList(list) do
    IO.puts("Tamanho da lista: #{lengthList(list)}")
    IO.puts("Tamanho da lista com TCO: #{lengthTCO(list)}")
  end

  # Recursão -> começa a soma apenas na volta, cada chamada espera a próxima terminar
  def lengthList(list), do: accLengthList(list)
  defp accLengthList([]), do: 0
  defp accLengthList([_ | tail]), do: 1 + accLengthList(tail)

  # Recursão de cauda -> acumulador guarda o resultado parcial, nada fica pendente após
  # a chamada recursiva (memória constante)
  def lengthTCO(list), do: accLengthTCO(list, 0)
  defp accLengthTCO([], acc), do: acc
  defp accLengthTCO([_ | tail], acc), do: accLengthTCO(tail, acc + 1)

end

defmodule Exercise2 do

  def fatorial(n) when n >= 0, do: accFatorial(n, 1)

  defp accFatorial(0, acc), do: acc
  defp accFatorial(n, acc), do: accFatorial(n - 1, acc * n)

  def printFatorial do
    n = IO.gets("Digite um número: ")
    |> String.trim()
    |> String.to_integer()

    IO.puts("Fatorial de #{n}! = #{fatorial(n)}")
  end

end

# Exercise1.printList(list)
# newListBegin = Exercise1.addBeginList("Primeiro", list)
# Exercise1.printList(newListBegin)
# newListEnd = Exercise1.addEndList("Último", newListBegin)
# Exercise1.printList(newListEnd)
# Exercise1.printFirst(newListEnd)
# Exercise1.printLengthList(newListEnd)
Exercise2.printFatorial()
