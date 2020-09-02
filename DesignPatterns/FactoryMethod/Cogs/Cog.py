# Python imports
from abc import ABCMeta, abstractmethod, abstractproperty

class Cog(metaclass=ABCMeta):
  def __init__(self):
    assert not callable(self.name)
    assert not callable(self.cogType)
    assert not callable(self.examine)

  @property
  @abstractmethod
  def name(self) -> str:
    """Name of the cog.
    :return: The name of the cog
    """
    pass

  @property
  @abstractmethod
  def cogType(self):
    """Type of cog
    :return: The type of cog
    :rtype: CogType
    """
    pass

  @property
  @abstractmethod
  def examine(self) -> str:
    """Show examine text on a cog.
    :return: The examine text
    """
    pass

